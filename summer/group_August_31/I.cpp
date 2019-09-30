#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
LL T, n, k, MOD, k_pow[60];
int main()
{
    LL T;
    scanf("%lld", &T);
    for(LL kase = 1;kase <= T;++kase)
    {
        LL n, k, MOD;
        scanf("%lld%lld%lld", &n, &k, &MOD);
        k_pow[0] = 1;
        for(LL i = 1;i <= n;i++)
            k_pow[i] = k_pow[i-1] * (k+1) % MOD;
        LL ans = (k >= n ? 1 : k_pow[n-k]); // 1, 2, 3, 4, 5
        for(LL len = 2;len <= n-k;++len) // shift leftward
            ans = (ans + k_pow[n-k-1] * (n-k-len+1)) % MOD;
        for(LL len = 3;len <= n-k;++len) // shift rightward
            ans = (ans + k_pow[n-k-len+1] * (n-k-len+1)) % MOD;
        for(LL i = min(k, n);i >= 1;--i)
            ans = ans * i % MOD;
        printf("Case #%lld: %lld\n", kase, ans);
    }
    return 0;
}
