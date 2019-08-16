#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 110;
const LL MOD = 1e9+7;
int main()
{
    LL d, k, L, R, ans = 0;
    scanf("%lld%lld%lld%lld", &d, &k, &L, &R);
    ans = (R - L + 1) % MOD * (R - L + 1) % MOD;
    if(d != 1 && d != 3 && d != 9)
    {
        LL nine[10];
        memset(nine, 0, sizeof(nine));
        for(LL i = L;i <= R && i < L+9;i++)
            nine[i%9] = (R-i)/9 + 1;
        for(LL i = 0;i < 9;i++)
        {
            LL delta = 0;
            for(LL j = 9-i;j < 9;j++)
                delta = (delta + nine[i]%MOD*nine[j]%MOD)%MOD;
            ans = ((ans - delta)%MOD+MOD)%MOD;
        }
    }
    printf("%lld", ans);
    return 0;
}
/*
6
2
10
12
*/