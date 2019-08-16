#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5+5;
int w[maxn], parent[maxn];
int head[maxn<<1], to[maxn<<1], nxt[maxn<<1], cnt_of_edge = 0;
bool exist[maxn], vis[maxn];
vector<int> order;
void add_edge(int u, int v)
{
    cnt_of_edge++;
    to[cnt_of_edge] = v;
    nxt[cnt_of_edge] = head[u];
    head[u] = cnt_of_edge;
}
void bfs()
{
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while(!q.empty())
    {
        int u = q.front();q.pop();
        vis[u] = true;
        order.push_back(u);
        for(int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            if(vis[v]) continue;
            parent[v] = u;
            q.push(v);
        }
    }
}
int main()
{
    order.clear();
    int n, q;
    scanf("%d%d", &n, &q);
    w[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", w + i);
        vis[i] = false;
    }
    for(int i = 0;i < n-1;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    bfs();
    reverse(order.begin(), order.end());
    while(q--)
    {
        for(int i = 1;i <= n;i++)
            exist[i] = false;
        int m, ai;
        LL ans = 0;
        scanf("%d", &m);
        for(int i = 1;i <= m;i++)
        {
            scanf("%d", &ai);
            exist[ai] = true;
            ans += 1LL*w[ai];
        }
        for(int i = 0, len = order.size();i < len;)
        {
            int u = order[i];
            if(exist[u] == false){i++;continue;}
            int pa = parent[u];
            if(pa == 0 || exist[pa] == false){i++;continue;}
            int papa = parent[pa];
            LL w2 = 1LL*w[u];
            if(exist[papa]) w2 += 1LL*w[papa];
            int j;
            for(j = i+1;j < len;j++)
            {
                int v = order[j];
                if(exist[v] == false) continue;
                if(parent[v] != pa) break;
                w2 += 1LL*w[v];
            }
            if(w2 > )
        }
        printf("%lld\n", ans);
    }
    return 0;
}