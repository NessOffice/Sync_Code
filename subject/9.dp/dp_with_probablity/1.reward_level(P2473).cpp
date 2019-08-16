#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
double dp[maxn][1<<15];
int need[maxn], weigh[maxn];
int main()
{
	int k, n;
	scanf("%d%d", &k, &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", weigh + i);
		int needed;
		while(1)
		{
			scanf("%d", &needed);
			if(needed == 0) break;
			need[i] |= (1<<(needed-1));
		}
	}
	int maxs = 1 << n;
	for(int i = k;i > 0;i--)
		for(int st = 0;st < maxs;st++)
		{
			for(int j = 1;j <= n;j++)
				if((st&need[j]) == need[j])
					dp[i][st] += max(dp[i+1][st], dp[i+1][st|(1<<(j-1))] + weigh[j]);
				else
					dp[i][st] += dp[i+1][st];
			dp[i][st] /= n;
		}
	printf("%.6lf", dp[1][0]);
	return 0;
}
