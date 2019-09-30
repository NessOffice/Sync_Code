#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e3+5;
const LL INF = (1LL << 60LL);
LL n, m, a[maxn], sum[maxn], cost[maxn], dp[maxn][maxn], dec[maxn][maxn]; // dec[i, j] for the decision point for [i, j]
LL w(LL l, LL r){return cost[r]-cost[l] - sum[l]*(sum[r]-sum[l]);}
int main()
{
	while(1)
	{
		scanf("%lld%lld", &n, &m);
		if(!n && !m) break;
		m++;
		sum[0] = 0;
		for(LL i = 1;i <= n;i++)
		{
			scanf("%lld", a + i);
			sum[i] = sum[i-1] + a[i];
			cost[i] = cost[i-1] + (a[i] * sum[i-1]);
		}
		for(LL i = 1;i <= n;i++)
			dp[1][i] = cost[i],
			dec[1][i] = 1;
		for(LL i = 2;i <= m;i++) // divide them into i parts
		{
			dec[i][n+1] = n;
			for(LL j = n;j > i;j--) // the first j points
			{
				dp[i][j] = INF;
				for(LL k = dec[i-1][j];k <= dec[i][j+1];k++)
					if(dp[i-1][k] + w(k, j) < dp[i][j])
						dp[i][j] = dp[i-1][k] + w(k, j),
						dec[i][j] = k;
			}
		}
		printf("%lld\n", dp[m][n]);
	}
	return 0;
}
