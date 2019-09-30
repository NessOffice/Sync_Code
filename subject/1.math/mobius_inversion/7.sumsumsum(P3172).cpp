#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include<tr1/unordered_map>
using namespace std;
typedef long long LL;
tr1::unordered_map<LL, LL> sum_mu_big;
const LL maxn = 5e6+5;
const LL MOD = 1e9+7;
LL sum_mu[maxn];
bool isP[maxn];
LL P[maxn];
LL total = 0;
void init()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_mu[1] = 1;
	for(LL i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            sum_mu[i] = -1;
        }
		for(LL j = 1, prime = P[j];j <= total && i*prime < maxn;j++, prime = P[j])
		{
			isP[i*prime] = false;
			if(!(i%prime)) break;
            sum_mu[i*prime] = -sum_mu[i];
		}
	}
    for(LL i = 1;i < maxn;i++)
        sum_mu[i] = (sum_mu[i-1] + sum_mu[i]) % MOD;
}
LL calc_sum_mu(LL n)
{
    if(n < maxn) return sum_mu[n];
    if(sum_mu_big[n]) return sum_mu_big[n];
    LL ans = 1;
    for(LL l = 2, r;l <= n;l = r+1)
    {
        r = n/(n/l);
        ans = ((ans - (r-l+1)*calc_sum_mu(n/l) % MOD) % MOD + MOD) % MOD;
    }
    return sum_mu_big[n] = ans;
}
LL calc_sum_mu(LL l, LL r){return ((calc_sum_mu(r) - calc_sum_mu(l-1)) % MOD + MOD) % MOD;}
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
int main()
{
    init();
    LL N, K, L, R, n, ans = 0;
    scanf("%lld%lld%lld%lld", &N, &K, &L, &R);
    R /= K, L = (L-1)/K; // no +1
    for(LL l = 1, r;l <= R;l = r + 1)
    {
    	if(L/l) r = min(L/(L/l), R/(R/l));
        else r = R/(R/l);
        ans = ((ans + calc_sum_mu(l, r)*qpow(R/l-L/l, N) % MOD) % MOD + MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
