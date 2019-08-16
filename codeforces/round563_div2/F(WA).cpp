#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
int n, x, dep_x;
vector<int> G[maxn];
vector<int> heavy;
int sz[maxn], depth[maxn];
int count_sz(int u)
{
    sz[u] = 1;
    for(int i = G[u].size()-1;i >= 0;i--)
    {
        int v = G[u][i];
        if(depth[v] == -1)
        {
            depth[v] = depth[u] + 1;
            sz[u] += count_sz(v);
        }
    }
    return sz[u];
}
void get_heavy_link(int u)
{
    heavy.push_back(u);
    int heavy_son = -1;
    for(int i = G[u].size()-1;i >= 0;i--)
    {
        int v = G[u][i];
        if(sz[v] > sz[u]) continue;
        if(heavy_son == -1 || sz[v] > sz[heavy_son])
            heavy_son = v;
    }
    if(heavy_son != -1)
        get_heavy_link(heavy_son);
}
int query(char query_type, int u)
{
    printf("%c %d\n", query_type, u);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}
int dfs(int u) // u is the common ancesters of x and terminal -- the endpoint in this linked list
{
    heavy.clear();
    get_heavy_link(u);
    int v, dep_v, y, dep_y, dis_xv;
    v = heavy.back();
    dis_xv = query('d', v);
    dep_y = (dep_x + depth[v] - dis_xv) / 2;
    y = heavy[dep_y - depth[u]]; // y: the LCA of x and v
    if(dep_x == dep_y) return y;
    else return dfs(query('s', y));
}
int main()
{
    memset(depth, -1, sizeof(depth));
    memset(sz, 0, sizeof(sz));
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    depth[1] = 0;
    count_sz(1);
    dep_x = query('d', 1);
    printf("! %d\n", dfs(1));
    fflush(stdout);
    return 0;
}