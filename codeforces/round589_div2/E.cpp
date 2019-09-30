#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
LL qpow(LL base, LL expo)
{
    if(base < 0) base += MOD;
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
LL inv(LL x){return qpow(x, MOD-2);}
int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    LL ans = 0, Cni = 1; // ans = \sum (-1)^n Cni (k-1)^ni [k^(n-i)-(k-1)^(n-i)]^n
    for(LL i = 0;i <= n;i++)
    {
        if(i) Cni = Cni * (n-i+1) % MOD * inv(i) % MOD;
        // printf("[DEBUG]%lld %lld %lld %lld %lld\n", i, Cni, qpow(k, n-i), qpow(k-1, n-i), qpow(qpow(k, n-i) - qpow(k-1, n-i), n));
        LL now = Cni * qpow(k-1, i*n) % MOD * qpow(qpow(k, n-i) - qpow(k-1, n-i), n) % MOD;
        if(i & 1) now = MOD - now;
        ans = (ans + now) % MOD;
    }
    printf("%lld", (ans+MOD)%MOD);
    return 0;
}
