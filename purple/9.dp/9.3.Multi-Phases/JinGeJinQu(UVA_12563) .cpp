#include <cstdio>
#include <cstring>
const int maxn = 10000 + 10;
int n, t, w, dp[2][maxn];
int max(int a, int b){return a > b ? a : b;}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int T, n, t, w;
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d%d", &n, &t);
		memset(dp, -1, sizeof(dp));
		dp[0][0] = dp[1][0] = 0;
		int p = 1, ansn = 0, anst = t-1;
		while(n--)
		{
			scanf("%d", &w);
			for(int t0 = 0;t0 < t;t0++)
			{
				dp[p][t0] = dp[p^1][t0];
				if(t0 >= w && dp[p^1][t0-w] >= 0)
					dp[p][t0] = max(dp[p][t0], dp[p^1][t0-w]+1);
				ansn = max(ansn , dp[p][t0]);
			}
			p ^= 1;
		}
		while(dp[p^1][anst] != ansn) anst--;
		printf("Case %d: %d %d\n", kase, ansn+1, anst+678);
	}
	return 0;
}