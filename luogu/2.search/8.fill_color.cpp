#include <cstdio>
#include <cstring>
int n, a[40][40];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool valid(int x, int y){return (0 <= x && x <= n+1) && (0 <= y && y <= n+1);}//caution n+1
void dfs(int x, int y)
{
	a[x][y] = 2;
	for(int i = 0;i < 4;i++)
	{
		int newx = x+dx[i];
		int newy = y+dy[i];
		if(valid(newx, newy) && !a[newx][newy])
			dfs(newx, newy);
	}
}
int main()
{
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++)
		scanf("%d", &a[i][j]);
	dfs(0, 0);
	for(int i = 1;i <= n;i++)
	{
		printf("%d", 2-a[i][1]);
		for(int j = 2;j <= n;j++)
			printf(" %d", 2-a[i][j]);
		printf("\n");
	}
	return 0;
}