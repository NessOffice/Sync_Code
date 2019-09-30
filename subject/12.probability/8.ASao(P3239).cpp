#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 300;
double P[maxn], D[maxn], dp[maxn][maxn], dp_sum[maxn], pw[maxn][maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		memset(dp_sum, 0, sizeof(dp_sum));
		int n, r;
		scanf("%d%d", &n, &r);
		pw[0][0] = 1.0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf%lf", P + i, D + i);
			pw[i][0] = 1.0; // pw[i][j] for (1 - P[i])^j
			for(int j = 1;j <= r;j++)
				pw[i][j] = (1.0 - P[i]) * pw[i][j-1];
		}
		double ans = 0;
		dp[0][0] = 1.0;
		dp[1][0] = pw[1][r];
		dp[1][1] = 1 - pw[1][r];
		for(int i = 2;i <= n;i++)
		for(int j = 0;j <= min(i, r);j++)
		{
			if(j) dp[i][j] += dp[i-1][j-1] * (1.0 - pw[i][r-j+1]);
			if(i != j) dp[i][j] += dp[i-1][j] * pw[i][r-j];
		}
		for(int i = 1;i <= n;i++)
		for(int j = 0;j <= min(i-1, r);j++)
			dp_sum[i] += dp[i-1][j] * (1.0 - pw[i][r-j]);
		for(int i = 1;i <= n;i++)
			ans += dp_sum[i] * D[i];
		printf("%.10lf\n", ans);
	}
	return 0;
}
/*
2
3 2
0.5000 2
0.3000 3
0.9000 1

3 0
0.5000 2
0.3000 3
0.9000 1
*/