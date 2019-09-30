#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 110;
double ans[3][maxn], dp[maxn][maxn];
void init()
{
	ans[1][1] = 0;
	for(int i = 2;i < maxn;i++)
		ans[1][i] = ans[1][i-1] + 2.0 / i;
	for(int i = 0;i < maxn;i++)
	for(int j = 0;j < maxn;j++)
		dp[i][j] = 0;
	for(int i = 1;i < maxn;i++)
	{
		ans[2][i] = 0;
		dp[i][0] = 1;
		for(int j = 1;j < i;j++)
		{
			dp[i][j] = 0;
			for(int k = 1;k < i;k++)
				dp[i][j] += (dp[k][j-1] + dp[i-k][j-1] - dp[k][j-1]*dp[i-k][j-1]);
			dp[i][j] /= (i-1); // smart!
			ans[2][i] += dp[i][j];
		}
	}
}
int main()
{
	init();
	int q, d;
	scanf("%d%d", &q, &d);
	printf("%lf\n", ans[q][d]);
	return 0;
}
