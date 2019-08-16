#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL items[maxn];
int main()
{
    LL n, m, k, dis = 0, ans = 0, ptr = 1;
    scanf("%lld%lld%lld", &n, &m, &k);
    for(LL i = 1;i <= m;i++)
        scanf("%lld", items + i);
    while(dis < m)
    {
        LL fst = items[ptr] - dis;
        LL r = ((fst-1)/k + 1) * k;
        LL num = 0;
        while(ptr <= m && items[ptr] - dis <= r)
            num++, ptr++;
        dis += num;
        ans++;
    }
    printf("%lld", ans);
    return 0;
}
