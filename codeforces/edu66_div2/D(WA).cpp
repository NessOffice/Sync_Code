#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 3e5 + 5;
using namespace std;
LL a[maxn], sum[maxn], next_node[maxn];
LL ans = 0;
void split(LL n, LL k)
{
    if(k == 1)
    {
        ans += (sum[1] - sum[n+1]);
        return;
    }
    LL n_next = n;
    while(next_node[n_next] >= k)
        n_next = next_node[n_next];
    ans += k*(sum[n_next] - sum[n+1]);
    split(n_next-1, k-1);
}
int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    for(LL i = 1;i <= n;i++)
        scanf("%lld", &a[i]);
    memset(next_node, 0, sizeof(next_node));
    sum[n+1] = 0;
    for(LL i = n;i >= 1;i--)
        sum[i] = sum[i+1] + a[i];
    LL temp = 0, last = 0;
    for(LL i = 1;i <= n;i++)
    {
        temp += a[i];
        if(temp > 0)
            next_node[i] = last;
        if(a[i] > 0)
        {
            temp = 0;
            last = i;
        }
    }
    split(n, k);
    printf("%lld", ans);
    return 0;
}