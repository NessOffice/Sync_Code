#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 3e5 + 5;
using namespace std;
LL a[maxn], sum[maxn];
int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    sum[0] = 0;
    for(LL i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    sort(sum + 1, sum + n); // caution: not sum + n+1
    LL ans = k*sum[n];
    for(LL i = 1;i < k;i++)
        ans -= sum[i];
    printf("%lld", ans);
    return 0;
}