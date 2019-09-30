#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e5+5;
int n, k, cnt, head[maxn], to[maxn], nxt[maxn], vis[maxn];
void add_edge(int u, int v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
int dfs(int u)
{
    int ans = 1;
    vis[u] = 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(vis[v]) continue;
        ans += dfs(v);
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0;i < k;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i]) continue;
        else ans += (dfs(i)-1);
    }
    ans = k - ans;
    printf("%d", ans);
    return 0;
}
