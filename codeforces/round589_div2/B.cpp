#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1010;
const LL MOD = 1e9+7;
LL a[maxn][maxn];
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
    memset(a, -1, sizeof(a));
    LL n, m;
    bool ok = true;
    scanf("%lld%lld", &n, &m);
    for(LL i = 0;i < n;i++)
    {
        LL ri;
        scanf("%lld", &ri);
        for(LL j = 0;j < ri;j++)
            a[i][j] = 1;
        a[i][ri] = 0;
    }
    for(LL j = 0;j < m;j++)
    {
        LL ci;
        scanf("%lld", &ci);
        for(LL i = 0;i < ci;i++)
        {
            if(a[i][j] == 0)
                ok = false;
            a[i][j] = 1;
        }
        if(a[ci][j] == 1)
            ok = false;
        a[ci][j] = 0;
    }
    LL ans = 0;
    for(LL i = 0;i < n;i++)
    for(LL j = 0;j < m;j++)
        if(a[i][j] == -1)
            ans++;
    if(ok) printf("%lld\n", qpow(2, ans));
    else printf("0");
    return 0;
}