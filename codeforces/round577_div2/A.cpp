#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 4e5 + 5;
LL cnt[1005][5];
LL max_cnt(LL id)
{
    LL res = cnt[id][0];
    res = max(res, cnt[id][1]);
    res = max(res, cnt[id][2]);
    res = max(res, cnt[id][3]);
    res = max(res, cnt[id][4]);
    return res;
}
int main()
{
    LL n, m, ans = 0;
    char key[1005];
    scanf("%lld%lld", &n, &m);
    for(LL i = 0;i < n;i++)
    {
        scanf("%s", key);
        for(LL j = 0;j < m;j++)
            cnt[j][key[j]-'A']++;
    }
    LL w;
    for(LL j = 0;j < m;j++)
    {
        scanf("%lld", &w);
        ans += (w * max_cnt(j));
    }
    printf("%lld", ans);
    return 0;
}
