#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <tr1/unordered_map>
using namespace std;
typedef long long LL;
tr1::unordered_map<LL, LL> sum_phi_big;
tr1::unordered_map<LL, LL> sum_jordan_big;
const LL maxn = 5e6+5;
const LL MOD = 998244353;
LL sum_jordan[maxn];
LL sum_mu[maxn];
bool isP[maxn];
LL P[maxn];
LL total = 0;
void init()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_mu[1] = sum_jordan[1] = 1;
	for(LL i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            sum_mu[i] = -1;
            sum_jordan[i] = (i*i-1) % MOD;
        }
		for(LL j = 1, prime = P[j];j <= total && i*prime < maxn;j++, prime = P[j])
		{
			isP[i*prime] = false;
			if(!(i%prime))
            {
                sum_jordan[i*prime] = (prime * prime * sum_jordan[i]) % MOD;
                break;
            }
            sum_jordan[i*prime] = sum_jordan[prime] * sum_jordan[i] % MOD;
            sum_mu[i*prime] = -sum_mu[i];
		}
	}
    for(LL i = 1;i < maxn;i++)
        sum_jordan[i] = (sum_jordan[i] + sum_jordan[i-1]) % MOD;
}
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    base %= MOD;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL inv_6 = qpow(6, MOD-2);
LL calc_sum2(LL x){return x*(x+1)%MOD*(2*x+1)%MOD*inv_6%MOD;}
LL calc_sum(LL l, LL r){return r - l + 1;}
LL calc_sum_jordan(LL n)
{
    if(n < maxn) return sum_jordan[n];
    if(sum_jordan_big[n]) return sum_jordan_big[n];
    LL ans = calc_sum2(n);
    for(LL l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans = ((ans - calc_sum(l, r)*calc_sum_jordan(n / l) % MOD)+MOD)%MOD;
    }
    return sum_jordan_big[n] = ans;
}
LL calc_sum_jordan(LL l, LL r){return (calc_sum_jordan(r)-calc_sum_jordan(l-1)+MOD)%MOD;}
LL f(LL x, LL k)
{
    x %= MOD;
    LL ans = x*x%MOD;
    if(x == 1) return k; // caution!!!
    LL inv = qpow(x-1, MOD-2);
    LL son = (qpow(x, k)-1+MOD)%MOD;
    return ans*son%MOD*inv%MOD;
}
char k_str[100005];
LL fun[maxn];
int main()
{
    init();
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n;
        scanf("%lld", &n);
        scanf("%s", k_str);
        LL k = 0;
        for(LL i = 0, len = strlen(k_str);i < len;i++)
        {
            k = 10 * k + k_str[i]-'0';
            k %= (MOD-1); // phi(MOD)
        }
        k = k-1 + MOD-1;
        k %= (MOD-1);
        LL ans = 0;
        for(LL l = 1, r;l <= n;l = r + 1)
        {
            r = n/(n/l);
            ans = ((ans + calc_sum_jordan(l, r)*f(n/l, k)%MOD)%MOD+MOD)%MOD;
        }
        printf("%lld\n", (ans%MOD+MOD)%MOD);
    }
    return 0;
}
