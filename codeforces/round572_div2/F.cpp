#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e3 + 5;
const LL maxm = 1e5 + 5;
const LL MOD = 998244353;
LL delta[maxn], a[maxn], fac[maxm];
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
    for(LL i = 1;i < maxm;i++)
        fac[i] = fac[i-1] * i % MOD;
}
int main()
{
    init();
    LL n, k, ans = 0;
    scanf("%lld%lld", &n, &k);
    for(LL i = 1;i <= n;i++)
        scanf("%lld", a+i);
    for(LL i = 1;i <= n-k+1;i++)
    {
        LL len = n-i;
        for(LL j = i+1;j <= n;j++)
            delta[j-i] = abs(a[j] - a[i]);
        sort(delta+1, delta+len+1);
        LL last = -1;
        for(LL j = 1;j <= len;j++)
        {
            while(j <= k && delta[j] == last) j++;
            last = delta[j];
            ans += ((delta[j] * C(len-j, k-2)) % MOD);
        }
    }
    printf("%lld", ans);
    return 0;
}
