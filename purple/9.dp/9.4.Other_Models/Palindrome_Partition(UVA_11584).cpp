#include <cstdio>
#include <cstring>
const int maxn = 1000 + 10;
int n, len, palind[maxn][maxn], dp[maxn][maxn];
char s[maxn];
int min(int a, int b){return a < b ? a : b;}
int dfs(int i, int j)
{
	int& ans = dp[i][j];
	if(ans > 0) return ans;
	if(palind[i][j]) return ans = 1;
	for(int k = i;k <= j;k++)
		if(palind[k][j])
			if(ans < 0) ans = dfs(i, k-1) + 1;
			else ans = min(ans, dfs(i, k-1) + 1);
	return ans;
}
void divide()
{
	for(int i = 0, flag = 1;i < 2*len-1;flag = 1, i++)
	for(int j = 0;j <= i && j+i < 2*len-1;j++)
	{
		if((i-j) & 1) continue;
		if(s[(i-j)/2] != s[(i+j)/2]) flag = 0;
		palind[(i-j)/2][(i+j)/2] = flag;
	}
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		len = strlen(s);
		memset(palind, 0, sizeof(palind));
		memset(dp, -1, sizeof(dp));
		divide();
		printf("%d\n", dfs(0, len-1));
	}
	return 0;
}
