#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e8;
int main()
{
	int n, sum[300] = {0}, a[300];
	int minv = INF, maxv;
	int minf[300][300], maxf[300][300];
	memset(sum, 0, sizeof(sum));
	memset(maxf, -1, sizeof(maxf));
	memset(minf, -1, sizeof(minf));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
		minf[i][i] = minf[n+i][n+i] = maxf[i][i] = maxf[n+i][n+i] = 0;
	}
	for(int i = n+1;i <= 2*n;i++)
		sum[i] = sum[i-1] + a[i-n];
	for(int p = 1;p < n;p++)
		for(int i = 1, j = i+p;j < 2*n;i++, j++)
		{
			if(minf[i][j] == -1) minf[i][j] = INF;
			if(maxf[i][j] == -1) maxf[i][j] = 0;
			for(int k = i;k < j;k++)
			{
				minf[i][j] = min(minf[i][j], minf[i][k] + minf[k+1][j] + sum[j]-sum[i-1]);
				maxf[i][j] = max(maxf[i][j], maxf[i][k] + maxf[k+1][j] + sum[j]-sum[i-1]);
			}
		}
	for(int i = 1;i <= n;i++)
	{
		minv = min(minv, minf[i][i+n-1]);
		maxv = max(maxv, maxf[i][i+n-1]);
	}
	printf("%d\n%d\n", minv, maxv);
	return 0;
}
