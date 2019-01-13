#include <cstdio>
#include <cstring>
const int maxn = 21 + 2;
int ans, n, maxv, G[maxn][maxn], vis[maxn], route[maxn];
void init()
{
	ans = maxv = 0;
	memset(G, 0, sizeof(G));
	memset(vis, -1, sizeof(vis));
}
void join(int u)
{
	vis[u] = 0;
	for(int v = 1;v <= maxv;v++)
		if(vis[v] && G[u][v])
			join(v);
}
void dfs(int u, int d)
{
	route[d] = u;
	if(u == n)
	{
		ans++;
		for(int i = 0;i <= d;i++)
			printf("%c%d", i ? ' ' : '\n', route[i]);
		return;
	}
	vis[u] = 1;
	for(int v = 1;v <= maxv;v++)
	if(vis[v] == 0 && G[u][v])
		dfs(v, d + 1);
	vis[u] = 0;
}
int main()
{
	 freopen("in.txt", "r", stdin);
	 freopen("out.txt", "w", stdout);
	int kase = 0;
	while(scanf("%d", &n) == 1)
	{
		init();
		int u, v;
		while(scanf("%d%d", &u, &v), u)
		{
			G[u][v] = G[v][u] = 1;
			if(u > maxv) maxv = u;
			if(v > maxv) maxv = v;
		}
		printf("CASE %d:", ++kase);
		join(n);
		if(vis[1] == 0) dfs(1, 0);
		printf("\nThere are %d routes from the firestation to streetcorner %d.\n", ans, n);
	}
	return 0;
}
