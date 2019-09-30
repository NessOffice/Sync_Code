#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5;
int a[maxn], rgt[maxn], cnt[maxn];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        rgt[a[i]] = i;
        cnt[a[i]]++;
    }
    int l = 1;
    int ans = 0;
    while(l <= n)
    {
        int r = rgt[a[l]], cnt_now = 0;
        for(int i = l;i <= r;i++)
            r = max(r, rgt[a[i]]),
            cnt_now = max(cnt_now, cnt[a[i]]);
        ans += (r-l+1-cnt_now);
        l = r+1;
    }
    printf("%d", ans);
    return 0;
}
