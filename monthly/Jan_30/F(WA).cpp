#include <cstdio>
#include <cstring>
int n, m, cnt, G[1010][1010], vis[1010], in[1010];
void dfs(int u)
{
    vis[u] = 1;
    for(int v = 1;v <= n;v++)
    if(G[u][v] && !in[v])
    {
        in[v] = 1;
        cnt--;
        if(!vis[v]) dfs(v);
    }
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
        scanf("%d%d", &n, &m);
        int A, B;
        cnt = n;
        while(m--)
        {
            scanf("%d%d", &A, &B);
            G[A][B] = 1;
        }
        for(int i = 1;i <= n;i++)
            if(!vis[i]) dfs(i);
        // if(cnt == 0) cnt = 1;
        printf("%d\n", cnt);
    }
    return 0;
}