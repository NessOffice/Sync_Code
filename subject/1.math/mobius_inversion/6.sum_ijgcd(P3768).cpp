#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include<tr1/unordered_map>
using namespace std;
typedef long long LL;
tr1::unordered_map<LL, LL> sum_f_big;
const LL maxn = 5e6+5;
LL sum_f[maxn], inv6, inv4; // f = phi(n) * n * n
bool isP[maxn];
LL P[maxn], p;
LL total = 0;
LL mod_p(LL n){return (n % p + p) % p;}
void init()
{
	memset(isP, true, sizeof(isP));
	memset(P, 0, sizeof(P));
	isP[0] = isP[1] = false;
    sum_f[1] = 1;
	for(LL i = 2;i < maxn;i++)
	{
		if(isP[i])
        {
            P[++total]=i;
            sum_f[i] = i-1;
        }
		for(LL j = 1, prime = P[j];j <= total && i*prime < maxn;j++, prime = P[j])
		{
			isP[i*prime] = false;
			if(!(i%prime))
            {
                sum_f[i*prime] = prime * sum_f[i];
                break;
            }
            sum_f[i*prime] = sum_f[prime] * sum_f[i];
		}
	}
    for(LL i = 1;i < maxn;i++)
        sum_f[i] = mod_p(sum_f[i-1] + i*i%p*sum_f[i]%p);
}
// caution! (n %= p) is necessary for n may be greater than p!!! HOLY SHIT!!!
LL calc_sum_n3(LL n){n %= p;return n*n%p*(n+1)%p*(n+1)%p*inv4%p;} // n*n*(n+1)*(n+1)/4
LL calc_sum_n3(LL l, LL r){return mod_p(calc_sum_n3(r) - calc_sum_n3(l-1));}
LL calc_sum_n2(LL n){n %= p;return n*(n+1)%p*(2*n+1)%p*inv6%p;} // n*(n+1)*(2n+1)/6
LL calc_sum_n2(LL l, LL r){return mod_p(calc_sum_n2(r) - calc_sum_n2(l-1));}
LL calc_sum_f(LL n)
{
    if(n < maxn) return sum_f[n];
    if(sum_f_big[n]) return sum_f_big[n];
    LL ans = calc_sum_n3(n);
    for(LL l = 2, r;l <= n;l = r + 1)
    {
        r = n/(n/l);
        ans = mod_p(ans - calc_sum_n2(l, r)*calc_sum_f(n/l) % p);
    }
    return sum_f_big[n] = ans;
}
LL calc_sum_f(LL l, LL r){return mod_p(calc_sum_f(r) - calc_sum_f(l-1));}
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % p;
        expo >>= 1LL;
        base = base * base % p;
    }
    return ans;
}
int main()
{
    LL n, ans = 0;
    scanf("%lld%lld", &p, &n);
    inv4 = qpow(4, p-2);
    inv6 = qpow(6, p-2);
    init();
    for(LL l = 1, r;l <= n;l = r + 1)
    {
        r = n/(n/l);
        ans = mod_p(ans + calc_sum_f(l, r) * calc_sum_n3(n/l) % p);
    }
    printf("%lld", ans);
    return 0;
}
