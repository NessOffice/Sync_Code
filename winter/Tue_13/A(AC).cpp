#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
const int maxn = 110;
const int maxm = 1010;
bitset<maxm> facility[maxn];
bool G[maxn][maxn];
int n, k;
int color_cnt, cnt[maxn], color[maxn];
inline int rd(){int a;scanf("%d", &a);return a;}
void init()
{
    memset(G, 0, sizeof(G));
    for(int i = 0;i < maxn;i++)
        facility[i].reset();
}
bool check(int u, int d)
{
    for(int c = 0;c < d;c++)
        if(G[u][color[c]] == 0)
            return false;
    return true;
}
bool dfs(int node_new, int d)
{
    for(int u = node_new+1;u <= n;u++)
    {
        if(cnt[u] + d <= color_cnt) return false; // branch-cutting 1
        if(G[node_new][u] == 0) continue;
        color[d] = u;
        if(check(u, d))
        if(dfs(u, d+1))
            return true;
    }

    if(d > color_cnt){
        color_cnt = d;
        return true;
    }else
        return false;
}
void max_clique()
{
    memset(cnt, 0, sizeof(cnt));
    color_cnt = 0;

    for(int u = n;u;u--)
    {
        color[0] = u;
        dfs(u, 1);
        cnt[u] = color_cnt;
    }
}
int main()
{
    for(int T = rd();T;T--)
    {
        init();
        n = rd();
        k = rd();
        for(int i = 1;i <= n;i++)
            for(int m = rd();m;m--)
                facility[i].set(rd());
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                G[i][j] = G[j][i] = ((facility[i] & facility[j]).count() > 0);

        max_clique();
        printf("%lld\n", 1LL * color_cnt * k);
    }
    return 0;
}