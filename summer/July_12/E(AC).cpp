#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const LL maxn = 3010;
LL f[maxn], g[maxn];
LL qpow(LL base, LL expo)
{
    LL res = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            res = res * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return res;
}
LL inv(LL num){return qpow(num, MOD-2);}
int main()
{
    LL N, D;
    scanf("%lld%lld", &N, &D);
    f[1] = D, g[1] = 1;
    for(LL i = 2;i <= N;i++)
    {
        LL mom = inv(2*i-1);
        f[i] = (mom*D%MOD*f[i-1]%MOD + (2*i-2)*mom%MOD*g[i-1]) % MOD;
        g[i] = (mom*f[i-1]%MOD + (2*i-2)*mom%MOD*g[i-1]) % MOD;
    }
    LL ans = f[N];
    for(LL i = 1;i <= 2*N;i++)
        ans = ans * i % MOD;
    printf("%lld", ans);
    return 0;
}