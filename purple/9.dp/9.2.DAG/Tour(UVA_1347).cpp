#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int n, x[maxn], y[maxn], vis[maxn][maxn];
double dist[maxn][maxn], dp[maxn][maxn];
double dfs(int i, int j)
{
	if(vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	return dp[i][j] = min(dfs(i+1,j) + dist[i+1][i], dfs(i+1,i) + dist[i+1][j]);
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d", &x[i], &y[i]);
		for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			vis[i][j] = 0,
			dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		for(int j = 1;j < n;j++)
			vis[n][j] = 1, dp[n][j] = dist[n][j];
		printf("%.2lf\n", dfs(1, 1));
	}
	return 0;
}
