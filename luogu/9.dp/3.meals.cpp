#include <cstdio>
#include <cstring>
int dp[110][10010], a[110];
int main()
{
	int n, m, w;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++)
	for(int j = 0;j <= m;j++)
	{
		dp[0][0] = dp[i][0] = 1;
		dp[i][j] = dp[i-1][j];
		if(j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
