#include <cstdio>
#include <cstring>
const int MAXN = 110;
const char dir[] = "ensw";
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
char ans[MAXN];
int del[2*MAXN][2*MAXN], vis[2*MAXN][2*MAXN];
int n, k, cnt, T, sum[MAXN] = {0};
int abs(int a){return a > 0 ? a : -a;}
void dfs(int x, int y, int d, int last)
{
	if(d > n && x == MAXN && y == MAXN)
	{
		cnt++;
		for(int i = 1;i <= n;i++)
			putchar(ans[i]);
		putchar('\n');
	}
	if(d > n) return;
	if(del[x][y] || vis[x][y]) return;
	if(abs(x - MAXN) + abs(y - MAXN) > sum[n] - sum[d-1]) return;
	vis[x][y] = 1;
	for(int i = 0;i < 4;i++)
	{
		if(last == i || last + i == 3) continue;
		ans[d] = dir[i];
		int x2 = x, y2 = y, j;
		for(j = 0;j < d;j++)
		{
			x2 += dx[i], y2 += dy[i];
			if(del[x2][y2]) break;
		}
		if(j == d) dfs(x2, y2, d + 1, i);
	}
	vis[x][y] = 0;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	for(int i = 1;i < MAXN;i++) sum[i] = sum[i-1] + i;
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		memset(del, 0, sizeof(del));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &k);
		while(k--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			del[x + MAXN][y + MAXN] = 1;
		}
		dfs(MAXN, MAXN, 1, -1);
		printf("Found %d golygon(s).\n\n", cnt);
	}
	return 0;
}
