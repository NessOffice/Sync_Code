#include <cstdio>
typedef long long LL;
LL mod = 1000000007;
LL quick_power(LL expo, LL base)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1)
        {
            ans *= base;
            ans %= mod;
        }
        expo /= 2;
        base *= base;
        base %= mod;
    }
    return ans;
}
int main()
{
    LL N, K;
    while(~scanf("%lld%lld", &N, &K))
    {
        LL ans = 0, base;
        base = quick_power(K, 2) - 1;
        ans = quick_power(N, base);
        if(N & 1) ans += 1;
        else ans += base;
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}
