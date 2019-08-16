#include <cstdio>
#include <cstring>
const int maxn = 1e4 + 7;
int dp[2][maxn];
int max(int a, int b){return a > b ? a : b;}
int main()
{
	int n, m, w, p = 1;
	scanf("%d%d", &n, &m);
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[1][0] = 1;
	while(n--)
	{
		scanf("%d", &w);
		for(int m0 = 0;m0 <= m - w;m0++)
		{
			if(dp[p^1][m0] > 0)
			{
				dp[p][m0] = max(dp[p][m0], dp[p^1][m0]);
				dp[p][m0 + w] = max(dp[p][m0 + w], dp[p^1][m0 + w]);
				dp[p][m0 + w] += dp[p][m0];
			}
		}
		p ^= 1;
	}
	printf("%d\n", dp[p^1][m]);
	return 0;
}
