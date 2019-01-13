#include <cstdio>
#include <cstring>
const int maxn = 8 + 1;
int vis[maxn*maxn], grid[maxn][maxn], ans[maxn][maxn];
int cnt, join[maxn][maxn], value[maxn][maxn];
void print_table(int g[][maxn])
{
	for(int i = 0;i < 7;i++)
	{
		for(int j = 0;j < 8;j++)
			printf("%4d", g[i][j]);
		printf("\n");
	}
	printf("\n");
}
void dfs(int d, int j)
{
	if(d >= 7){cnt++;print_table(ans);putchar('\n');return;}
	if(j >= 8){dfs(d + 1, 0);return;}
	if(join[d][j]){dfs(d, j + 1);return;}
	for(int i = 2;i > 0;i--)//caution
	{
		if(i == 1 && (d == 6 || vis[value[grid[d][j]][grid[d+1][j]]])) continue;
		if(i == 2 && (j == 7 || vis[value[grid[d][j]][grid[d][j+1]]])) continue;
		if(i == 2 && (j == 7 || join[d][j+1])) continue;//caution
		if(i == 1){
			ans[d][j] = ans[d+1][j] = value[grid[d][j]][grid[d+1][j]];
			vis[ans[d][j]] = 1;
			join[d][j] = join[d+1][j] = 1;
			dfs(d, j + 1);
			vis[ans[d][j]] = 0;
			join[d][j] = join[d+1][j] = 0;
		}else{
			ans[d][j] = ans[d][j+1] = value[grid[d][j]][grid[d][j+1]];
			vis[value[grid[d][j]][grid[d][j+1]]] = 1;
			join[d][j] = join[d][j+1] = 1;
			dfs(d, j + 1);
			vis[value[grid[d][j]][grid[d][j+1]]] = 0;
			join[d][j] = join[d][j+1] = 0;
		}
	}
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out2.txt", "w", stdout);
	int kase = 0;
	for(int i = 0;i <= 6;i++)
	for(int j = 0;j <= 6;j++)
	{
		if(j < i) value[i][j] = value[j][i];
		if(j == i) value[i][j] = (i ? value[i-1][6] + 1 : 1);
		if(j > i) value[i][j] = value[i][j-1] + 1;
	}
	while(scanf("%d", &grid[0][0]) == 1)
	{
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(join, 0, sizeof(join));
		for(int j = 1;j < 8;j++)
			scanf("%d", &grid[0][j]);
		for(int i = 1;i < 7;i++)
		for(int j = 0;j < 8;j++)
			scanf("%d", &grid[i][j]);
		if(kase++) printf("\n\n\n");
		printf("Layout #%d:\n\n\n", kase);
		print_table(grid);
		printf("Maps resulting from layout #%d are:\n\n\n", kase);
		dfs(0, 0);
		printf("There are %d solution(s) for layout #%d.\n", cnt, kase);
	}
	return 0;
}
