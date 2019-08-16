#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
const int maxm = 5010;
struct Edge{int from, to, next;}edges[maxm];
int head[maxn];
int cnt_edge, cnt_color, color[maxn], color_deg_in[maxn];
int dfn[maxn], low[maxn], in_sta[maxn], sta[maxn], top, depth;
void tarjan(int u)
{
    depth++;
    dfn[u] = depth;
    low[u] = depth;
    in_sta[u] = 1;
    sta[++top] = u;
    for(int i = head[u];i;i = edges[i].next)
    {
        int v = edges[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_sta[v])
            low[u] = min(low[u], low[v]);
    }
    if(dfn[u] == low[u])
    {
        do{
            int top_elem = sta[top];
            color[top_elem] = cnt_color;
            in_sta[top_elem] = 0;
        }while(sta[top--] != u);
        cnt_color++;
    }
}
void add_edge(int u, int v, int index)
{
    edges[index].from = u;
    edges[index].to = v;
    edges[index].next = head[u];
    head[u] = index;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        depth = top = 0;
        cnt_edge = cnt_color = 0;
        memset(head, 0, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(sta, 0, sizeof(sta));
        memset(in_sta, 0, sizeof(in_sta));

        memset(color, 0, sizeof(color));
        memset(color_deg_in, 0, sizeof(color_deg_in));
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= m;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v, i);
        }
        for(int u = 1;u <= n;u++)
            if(!dfn[u]) tarjan(u);
        for(int i = 1;i <= m;i++)
        {
            int from_color, to_color;
            from_color = color[edges[i].from];
            to_color = color[edges[i].to];
            if(from_color == to_color) continue; // caution!
            color_deg_in[to_color]++;
        }
        int ans = 0;
        for(int c = 0;c < cnt_color;c++)
            if(color_deg_in[c] == 0) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
/*
3
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6

4 3
1 2
1 4
1 3

3 2
1 2
1 3

*/