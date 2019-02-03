#include <cstdio>
const int maxn = 100 + 10;
int data[maxn][maxn], dp[maxn][maxn], next[maxn][maxn];
void updata(int i, int j, int i1, int i2)
{
	if((dp[i2][j+1] < dp[i1][j+1])
	||(i2 < i1 && dp[i2][j+1] == dp[i1][j+1]))
		next[i][j] = i2;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int r, c;
	while(scanf("%d%d", &r, &c) == 2)
	{
		for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++)
			scanf("%d", &data[i][j]);
		for(int i = 0;i < r;i++)
			dp[i][c-1] = data[i][c-1];
		for(int j = c-2;j >= 0;j--)
		for(int i = 0;i < r;i++)
		{
			next[i][j] = (i+r-1)%r;
			updata(i, j, next[i][j], i);
			updata(i, j, next[i][j], (i+1)%r);
			dp[i][j] = data[i][j] + dp[next[i][j]][j+1];
		}
		int minr = 0, ans;
		for(int i = 1;i < r;i++)
			if(dp[i][0] < dp[minr][0]) minr = i;
		printf("%d", minr+1);
		ans = dp[minr][0];
		for(int j = 0;j < c-1;j++)
			printf(" %d", next[minr][j]+1),
			minr = next[minr][j];
		printf("\n%d\n", ans);
	}
	return 0;
}
