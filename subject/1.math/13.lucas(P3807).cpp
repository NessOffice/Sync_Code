#include <cstdio>
typedef long long LL;
const LL MAXN = 1e5 + 10;
LL fac[MAXN], p;
void init()
{
    fac[0] = 1;
    for(LL i = 1;i <= p;i++)
        fac[i] = fac[i-1] * i % p;
}
LL qpow(LL base,LL expo)
{
	base %= p;
    LL ans = 1;
    while(expo)
    {
        if(expo & 1)
            ans = ans % p * base % p;
        expo >>= 1;
        base = base % p * base % p;
    }
    return ans % p;
}
LL inv(LL num)
{
    return qpow(num, p - 2) % p;
}
LL C(LL n, LL m)
{
    if(m > n) return 0;
    return fac[n] * inv(fac[m] * fac[n-m]) % p;
}
LL lucas(LL n, LL m)
{
    if(n <= p && m <= p) return C(n, m);
    return lucas(n / p, m / p) * lucas(n % p, m % p) % p;
}
int main()
{
    LL T, n, m;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        init();
        printf("%lld\n", lucas(n + m, m));
    }
    return 0;
}
