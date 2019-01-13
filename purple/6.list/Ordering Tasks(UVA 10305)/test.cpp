#include <cstdio>
#include <cstring>
const int maxn = 100 + 4;
int n, m, pos, G[maxn][maxn], vis[maxn], out[maxn];
void topoDFS(int u)
{
	vis[u] = -1;
	for(int v = 1;v <= n;v++)
		if(G[u][v] && !vis[v]) topoDFS(v);
	vis[u] = 1, out[pos++] = u;
}
int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d%d", &n, &m) && (m || n))
	{
		memset(vis, 0, sizeof(vis));
		memset(G, 0, sizeof(G));
		pos = 0;
		int u, v;
		while(m--)
		{
			scanf("%d%d", &u, &v);
			G[u][v] = 1;
		}
		for(int i = 1;i <= n;i++)
			if(!vis[i]) topoDFS(i);
		while(pos--)
		{
			printf("%d", out[pos]);
			printf("%c", pos == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
