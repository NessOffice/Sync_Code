#include <cstdio>
typedef long long LL;
const LL MOD = 100000007;
const LL maxn = 100007;
LL fac[maxn];
LL qpow(LL base,LL expo)
{
    LL ans = 1;
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
    if(m > n || m < 0) return 0;
    LL son = fac[n], mom = fac[n-m]*fac[m] % MOD;
    return son * qpow(mom, MOD-2) % MOD;
}
void init()
{
    fac[0] = 1;
    for(LL i = 1;i < maxn;i++)
        fac[i] = fac[i-1]*i % MOD;
}
LL solve(LL n, LL k)
{
    LL ans = C(n-1, k-1);
    for(LL i = 2;i < n;i++)
        if(n % i == 0) ans = (ans + MOD - solve(n/i, k)) % MOD;
    return ans;
}
int main()
{
    init();
    LL T, n, k;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", solve(n, k));
    }
    return 0;
}