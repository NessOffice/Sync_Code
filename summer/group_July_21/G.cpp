#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL INF = 1e17;
LL dp[2][2][2][10][10];
int main()
{
	LL n, k, w, now = 1, ans = INF;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][1][0][0][0] = 0;
	scanf("%lld%lld", &n, &k);
	for(LL i = 1;i <= n;i++)
	{
		memset(dp[now], 0x3f, sizeof(dp[now]));
		scanf("%lld", &w);
		for(LL a = 0;a <= k;a++)
		for(LL b = 0;b <= k;b++)
		for(LL x = 0;x < 2;x++)
		for(LL y = 0;y < 2;y++)
		{
			if(dp[now^1][x][y][a][b] > INF) continue;
			dp[now][y][1][a][b] = min(dp[now][x][1][a][b], dp[now^1][x][y][a][b] + w);
			if(x || y) dp[now][y][0][a][b] = min(dp[now][y][0][a][b], dp[now^1][x][y][a][b]);
			if(b < k) dp[now][y][1][a][b+1] = min(dp[now][y][1][a][b+1], dp[now^1][x][y][a][b]);
			if(a < k && (x || y)) dp[now][y][0][a+1][b] = min(dp[now][y][0][a+1][b], dp[now^1][x][y][a][b] + w);
		}
		now ^= 1;
	}
	for(LL i = 0;i <= k;i++)
	for(LL x = 0;x < 2;x++)
	for(LL y = 0;y < 2;y++)
		if(x || y) ans = min(ans, dp[now^1][x][y][i][i]);
	printf("%lld", ans);
	return 0;
}
