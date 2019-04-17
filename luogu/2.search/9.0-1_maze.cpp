#include <cstdio>
#include <cstring>
int n, m, ans, vis[1010][1010], a[1010][1010], cnt[1010][1010];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool valid(int x, int y){return (0 < x && x <= n) && (0 < y && y <= n);}
void dfs2(int x, int y)
{
	cnt[x][y] = ans;
	vis[x][y] = 2;
	for(int i = 0;i < 4;i++)
	{
		int newx = x+dx[i];
		int newy = y+dy[i];
		if(valid(newx, newy) && vis[newx][newy] == 1)
			dfs2(newx, newy);
	}
}
void dfs1(int x, int y)//find connection
{
	ans++;
	vis[x][y] = 1;
	for(int i = 0;i < 4;i++)
	{
		int newx = x+dx[i];
		int newy = y+dy[i];
		if(!valid(newx, newy)) continue;
		if(!vis[newx][newy] && a[newx][newy] != a[x][y])
			dfs1(newx, newy);
	}
	// if(vis[x][y] != 2) dfs2(x, y);//what's wrong?
}
int main()
{
	memset(vis, 0, sizeof(vis));
	memset(a, 0, sizeof(a));
	scanf("%d%d", &n, &m);
	char s[1010];
	for(int i = 1;i <= n;i++)
	{
		scanf("%s", s+1);
		for(int j = 1;j <= n;j++)
			a[i][j] = s[j]-'0';
	}
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++, ans = 0)
		if(!vis[i][j]){dfs1(i, j);dfs2(i, j);}
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", cnt[x][y]);
	}
	return 0;
}