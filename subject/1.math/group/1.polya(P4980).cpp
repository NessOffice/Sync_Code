#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
const LL MOD = 1e9+7;
LL inv_n;
LL qpow(LL base, LL expo)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
LL calc_phi(LL n)
{
    LL ans = 1;
    for(LL d = 2;d*d <= n;d++)
    {
        if(n % d) continue;
        n /= d, ans *= (d-1);
        while(n % d == 0)
            n /= d,
            ans *= d;
    }
    if(n > 1)
        ans = ans * (n-1);
    return ans;
}
LL polya(LL m, LL n)
{
    LL ans = 0;
    for(LL d = 1;d*d <= n;d++)
    {
        if(n % d) continue;
        ans = ((ans + inv_n * calc_phi(d) % MOD * qpow(m, n/d) % MOD) % MOD + MOD) % MOD;
        if(d*d != n) ans = ((ans + inv_n * calc_phi(n/d) % MOD * qpow(m, d) % MOD) % MOD + MOD) % MOD;
    }
    return ans;
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n;
        scanf("%lld", &n);
        inv_n = qpow(n, MOD-2);
        printf("%lld\n", polya(n, n));
    }
    return 0;
}
