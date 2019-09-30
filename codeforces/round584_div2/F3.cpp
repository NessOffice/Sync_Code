#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2.4e6+10; // caution
const int MOD = 1e9+7;
int n, m, cnt, ans[maxn], vis[maxn];
vector<int> edge[maxn][12];
void add_edge(int u, int v, int w)
{
    while(w >= 10)
        edge[++cnt][w % 10].push_back(v),
        v = cnt, w /= 10;
    edge[u][w].push_back(v);
}
vector<vector<int> > q, q2;
void bfs()
{
    vis[1] = 1;
    q.push_back(vector<int>(1, 1));
    while(!q.empty())
    {
        for(int i = 0, sz1 = q.size();i < sz1;i++) // traverse different parts by order
        {
            for(int w = 0;w < 10;w++)
            {
                vector<int> vec_temp(0);
                for(int j = 0, sz2 = q[i].size();j < sz2;j++)
                {
                    int u = q[i][j];
                    for(int k = 0, sz2 = edge[u][w].size();k < sz2;k++)
                    {
                        int v = edge[u][w][k];
                        if(vis[v]) continue;
                        vis[v] = 1;
                        ans[v] = (10LL * ans[u] + w) % MOD;
                        vec_temp.push_back(v);
                    }
                    
                }
                if(!vec_temp.empty())
                    q2.push_back(vec_temp);
            }
        }
        q = q2, q2.clear();
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    cnt = n;
    for(int i = 1;i <= m;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v, i);
        add_edge(v, u, i);
    }
    bfs();
    for(int i = 2;i <= n;i++)
        printf("%d\n", ans[i]);
    return 0;
}
