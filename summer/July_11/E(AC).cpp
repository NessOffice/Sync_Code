#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
vector<int> order;
int n, parent[maxn], sz[maxn];
int head[maxn], to[maxn], nxt[maxn];
void bfs()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        order.push_back(u);
        for(int i = head[u];i;i = nxt[i])
            q.push(to[i]);
    }
}
void init()
{
    for(int i = 0;i <= n;i++)
    {
        head[i] = 0;
        parent[i] = 0;
        sz[i] = 0;
    }
    order.clear();
}
void add_edge(int index, int u, int v)
{
    to[index] = v;
    nxt[index] = head[u];
    head[u] = index;
    sz[u]++;
    parent[v] = u;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        init();
        for(int i = 2;i <= n;i++)
        {
            int u;
            scanf("%d", &u);
            add_edge(i, u, i);
        }
        bfs();
        reverse(order.begin(), order.end());
        int ans = 0;
        for(int i = 0, len = order.size();i < len;i++)
        {
            int u = order[i];
            int pa = parent[u];
            if(!pa || sz[pa] < 2) continue;
            int papa = parent[pa];
            if(!papa || sz[papa] < 3) continue;
            int papapa = parent[papa];
            if(!papapa || sz[papapa] < 1) continue;
            sz[pa] = sz[papa] = 0, sz[papapa]--, ans++; // paint a stick man
        }
        printf("%d\n", ans);
    }
    return 0;
}
