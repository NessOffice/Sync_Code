#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
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
int main()
{
    LL x, y, ans = 1;
    scanf("%lld%lld", &x, &y);
    for(LL p = 2, limit = sqrt(x);p <= limit;p++)
    {
        if(x % p) continue;
        while(x % p == 0) x /= p;
        LL expo = 0;
        LL y_ = y;
        while(y_)
        {
            expo += y_ / p;
            expo %= (MOD-1);
            y_ /= p;
        }
        ans = ans * qpow(p, expo) % MOD;
    }
    if(x != 1)
    {
        LL expo = 0;
        LL y_ = y;
        while(y_)
        {
            expo += y_ / x;
            expo %= (MOD-1);
            y_ /= x;
        }
        ans = ans * qpow(x, expo) % MOD;
    }
    printf("%lld", ans);
    return 0;
}
