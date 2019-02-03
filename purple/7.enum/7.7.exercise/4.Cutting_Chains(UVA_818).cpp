#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 15 + 2;
int G[maxn][maxn], cut[maxn], vis[maxn];
int n, ans, open, num;
bool dfs(int u, int last)
{
	vis[u] = 1;
	for(int v = 1;v <= n;v++)
	{
		if(v == last || cut[v]) continue;//caution
		if(G[u][v])
		{
			if(vis[v]) return true;
			if(dfs(v, u)) return true;
		}
	}
	return false;
}
bool circle()
{
	memset(vis, 0, sizeof(vis));
	for(int u = 1;u <= n;u++)
	if(!vis[u] && !cut[u])
	{
		num++;
		if(dfs(u, -1)) return true;
	}
	return false;
}
bool invalid()
{
	int edge;
	for(int u = 1;u <= n;u++)
	{
		edge = 0;
		if(cut[u]) continue;
		for(int v = 1;v <= n;v++)
		{
			if(cut[v]) continue;
			if(G[u][v]) edge++;
			if(edge > 2) return true;
		}
	}
	return false;
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int kase = 0, u, v;
	while(scanf("%d", &n) && n)
	{
		memset(G, 0, sizeof(G));
		while(scanf("%d%d", &u, &v) && u != -1)
			G[u][v] = G[v][u] = 1;
		ans = maxn;
		for(int i = 0;i < (1<<n);i++)
		{
			memset(cut, 0, sizeof(cut));
			int temp = i;
			num = open = 0;
			for(int j = 1;temp;j++)
			{
				if(temp&1)
					cut[j] = 1,
					open++;
				temp /= 2;
			}
			if(open >= ans) continue;
			if(circle() || invalid()) continue;
			if(num-1 <= open) ans = open;//caution
		}
		printf("Set %d: Minimum links to open is %d\n", ++kase, ans);
	}
	return 0;
}
