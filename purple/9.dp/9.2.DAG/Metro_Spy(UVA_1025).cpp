#include <cstdio>
#include <cstring>
const int maxm = 250 + 5;
const int maxn = 50 + 5;
const int INF = 10000000;
int min(int a, int b){return a < b ? a : b;}
int N, T, t[maxm], dp[maxm][maxn], has_train[maxm][maxn][2];
int main()
{
	int kase = 0, M;
	while(scanf("%d", &N) && N)
	{
		memset(has_train, 0, sizeof(has_train));
		memset(dp, -1, sizeof(dp));
		scanf("%d", &T);
		for(int i = 1;i < N;i++)
			scanf("%d", &t[i]);
		scanf("%d", &M);
		int t0;
		while(M--)
		{
			scanf("%d", &t0);
			for(int i = 1;i < N && t0 <= T;i++)
			{
				has_train[t0][i][0] = 1;
				t0 += t[i];
			}
		}
		scanf("%d", &M);
		while(M--)
		{
			scanf("%d", &t0);
			for(int i = N;i > 1 && t0 <= T;i--)
			{
				has_train[t0][i][1] = 1;
				t0 += t[i-1];
			}
		}
		dp[T][N] = 0;
		for(int i = 1;i < N;i++)
			dp[T][i] = INF;
		for(t0 = T-1;t0 >= 0;t0--)
		for(int i = 1;i <= N;i++)
		{
			dp[t0][i] = dp[t0+1][i] + 1;
			if(i < N && has_train[t0][i][0] && t0 + t[i] <= T)
				dp[t0][i] = min(dp[t0][i], dp[t0+t[i]][i+1]);
			if(i > 1 && has_train[t0][i][1] && t0 + t[i-1] <= T)
				dp[t0][i] = min(dp[t0][i], dp[t0+t[i-1]][i-1]);
		}
		int ans = dp[0][1];
		printf("Case Number %d: ", ++kase);
		if(ans >= INF) printf("impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}
