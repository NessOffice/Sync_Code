#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
const LL maxn = 2e5+5;
const LL MOD = 1e9+7;
LL n, m, q, a[maxn], re[21], sum;
LL query(LL l, LL r)
{
    if(l == r) return a[l] % m ? 0 : 1;
    LL ans = 0, mid = (l + r) / 2;
    ans = (ans + query(l, mid)) % MOD;
    ans = (ans + query(mid+1, r)) % MOD;
    sum = a[mid+1] % m;
    memset(re, 0, sizeof(re));
    re[sum]++;
    for(LL i = mid+2;i <= r;i++)
    {
        sum = (sum + a[i]) % m;
        re[sum]++;
    }
    sum = a[mid] % m;
    ans = (ans + re[m - sum]) % MOD;
    for(int i = mid-1;i >= l;i--)
    {
        sum = (sum + a[i]) % m;
        ans = (ans + re[m - sum]) % MOD;
    }
    return (ans + 1) % MOD;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for(LL i = 1;i <= n;i++) scanf("%lld", a+i);
    scanf("%lld", &q);
    while(q--)
    {
        LL x, y;
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", query(x, y));
    }
    return 0;
}
