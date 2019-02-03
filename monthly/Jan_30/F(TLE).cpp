#include <cstdio>
#include <cstring>
int n, m, cnt, tot, top, G[1010][1010], vis[1010], in[1010];
void dfs(int u)
{
    vis[u] = 1;
    for(int v = 1;v <= n;v++)
    {
        if(G[u][v])
        {
            if(!in[v]) in[v] = 1;
            if(!vis[v]) dfs(v);
        }
        if(G[v][u])
        {
            if(!in[u]) in[u] = 1;
            if(!vis[v]) dfs(v);
        }
    }
    tot++;
    if(in[u]) top++;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        cnt = 0;
        scanf("%d%d", &n, &m);
        int A, B;
        while(m--)
        {
            scanf("%d%d", &A, &B);
            G[A][B] = 1;
        }
        for(int i = 1;i <= n;i++)
        {
            if(vis[i]) continue;
            tot = top = 0;
            dfs(i);
            top = tot - top;
            cnt += (top ? top : 1);
        }
        printf("%d\n", cnt);
    }
    return 0;
}