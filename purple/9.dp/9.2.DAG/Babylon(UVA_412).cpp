#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 30 + 2;
int a[maxn][3], G[3*maxn][3*maxn], dp[3*maxn], n;
void cover(int u, int v)
{
	int w, h, w2, h2;
	for(int d = 0;d < 3;d++)
	{
		switch(d)
		{
			case 0:w = min(a[u][1], a[u][2]), h = max(a[u][1], a[u][2]);break;
			case 1:w = min(a[u][0], a[u][2]), h = max(a[u][0], a[u][2]);break;
			case 2:w = min(a[u][1], a[u][0]), h = max(a[u][1], a[u][0]);break;
		}
		for(int d2 = 0;d2 < 3;d2++)
		{
			switch(d2)
			{
				case 0:w2 = min(a[v][1], a[v][2]), h2 = max(a[v][1], a[v][2]);break;
				case 1:w2 = min(a[v][0], a[v][2]), h2 = max(a[v][0], a[v][2]);break;
				case 2:w2 = min(a[v][1], a[v][0]), h2 = max(a[v][1], a[v][0]);break;
			}
			if(w < w2 && h < h2) G[d*maxn+u][d2*maxn+v] = 1;
		}
	}
}
int dfs(int u, int d)
{
	int& ans = dp[d*maxn+u];
	if(ans) return ans;
	ans = a[u][d];
	for(int v = 0;v < n;v++)
	for(int d2 = 0;d2 < 3;d2++)
		if(G[d*maxn+u][d2*maxn+v])
			ans = max(ans, dfs(v, d2) + a[u][d]);
	return ans;
}
int main()
{
	int kase = 0;
	while(scanf("%d", &n), n)
	{
		int maxh = 0;
		memset(dp, 0, sizeof(dp));
		memset(G, 0, sizeof(G));
		for(int u = 0;u < n;u++)
		for(int d = 0;d < 3;d++)
			scanf("%d", &a[u][d]);
		for(int u = 0;u < n;u++)
		for(int v = 0;v < n;v++)
			cover(u, v);
		for(int u = 0;u < n;u++)
		for(int d = 0;d < 3;d++)
			maxh = max(maxh, dfs(u, d));
		printf("Case %d: maximum height = %d\n", ++kase, maxh);
	}
	return 0;
}
