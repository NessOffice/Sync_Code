#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6+5;
int n, a[maxn], dep[maxn];
int head[maxn], to[maxn], nxt[maxn], pa[maxn], cnt_of_edge;
void add_edge(int u, int v)
{
    cnt_of_edge++;
    to[cnt_of_edge] = v;
    nxt[cnt_of_edge] = head[u];
    head[u] = cnt_of_edge;
}
int solve()
{
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > q;
    q.push(make_pair(a[1] + dep[1], 1));
    int t = n-1, ans = 0;
    while(!q.empty())
    {
        pair<int, int> pii = q.top();q.pop();
        ans = max(ans, pii.first + t);
        t--;
        int u = pii.second;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = to[i];
            if(v == pa[u]) continue;
            q.push(make_pair(a[v] + dep[v], v));
        }
    }
    return ans;
}
void dfs(int u, int d)
{
    dep[u] = d;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == pa[u]) continue;
        pa[v] = u;
        dfs(v, d+1);
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", a + i);
    for(int i = 1;i < n;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    printf("%d\n", solve());
    return 0;
}
/*
5
2 3 5 2 1
2 1
3 2
2 4
1 5

6
1 99 101 1 1 1
1 2
1 3
2 4
2 5
2 6
*/