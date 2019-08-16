#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
const int MOD = 998244353;
vector<int> G[maxn];
int fac[maxn], vis[maxn], ans;
void calc_fac()
{
    fac[0] = 1;
    for(int i = 1;i < maxn;i++)
        fac[i] = (int)(1LL * fac[i-1] * i % MOD);
}
void dfs(int u)
{
    vis[u] = 1;
    ans = (int)(1LL * ans * fac[G[u].size()] % MOD);
    for(int i = G[u].size()-1;i >= 0;i--)
    {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    calc_fac();
    int n;
    scanf("%d", &n);
    ans = n;
    for(int i = 1;i < n;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}
