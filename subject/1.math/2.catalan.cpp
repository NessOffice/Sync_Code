#include <cstdio>
typedef long long LL;
const LL MOD = 20100403;
const LL maxn = 2e6 + 7;
LL fac[maxn];
LL qpow(LL base,LL expo)
{
    LL ans = 1;
    base %= MOD;
    while(expo)
    {
        if(expo & 1)
            ans = ans*base % MOD;
        expo >>= 1;
        base = base*base % MOD;
    }
    return ans;
}
LL C(LL n, LL m)
{
    LL son = fac[n], mom = fac[n-m]*fac[m] % MOD;
    return son * qpow(mom, MOD-2) % MOD;
}
void init()
{
    fac[0] = 1;
    for(LL i = 1;i < maxn;i++)
        fac[i] = fac[i-1]*i % MOD;
}
int main()
{
    init();
    LL n, m;
    scanf("%lld%lld", &n, &m);
    LL ans = C(n+m, m) - C(n+m, m-1) + MOD;
    printf("%lld\n", ans % MOD);
	return 0;
}
