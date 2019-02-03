#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int maxn = 15 + 2;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char maze[maxn][maxn];
int r, c, vis[maxn][maxn], vis2[maxn][maxn];
struct Node{
	int len;
	char num[2*maxn];
	void clear(){len = 0;}
}temp, ans;
bool valid(int x, int y, char type)
{
	if(x < 0 || x >= r) return false;
	if(y < 0 || y >= c) return false;
	if(maze[x][y] == '#') return false;
	if(type == 'd') return !vis[x][y];
	else return !vis2[x][y];
}
int bfs(int x0, int y0)
{
	int cnt = 0, head = 0, tail = 1;
	memcpy(vis2, vis, sizeof(vis));
	int qx[2*maxn], qy[2*maxn];
	qx[0] = x0, qy[0] = y0;
	while(head < tail)
	{
		int newx, newy, x, y;
		x = qx[head];
		y = qy[head];
		head++;
		for(int dir = 0;dir < 4;dir++)//rough estimation
		{
			newx = x + dx[dir];
			newy = y + dy[dir];
			if(valid(newx, newy, 'b'))
			{
				qx[tail] = newx;
				qy[tail] = newy;
				vis2[newx][newy] = 1;
				tail++, cnt++; 
			}
		}
	}
	return cnt;
}
bool cmp(int x, int y, int cnt)
{
	if(cnt+1 > ans.len) return true;
	int maxlen = bfs(x, y);
	if(cnt+1 + maxlen < ans.len) return false;
	if(cnt+1 + maxlen > ans.len) return true;
	if(cnt+1 + maxlen == ans.len)
		for(int i = 0;i <= cnt;i++)
		if(temp.num[i] < ans.num[i]) return false;
		else if(temp.num[i] > ans.num[i]) return true;
	return true;
}
void dfs(int x, int y, int cnt)
{
	temp.num[cnt] = maze[x][y];
	if(cnt+1 > temp.len) temp.len = cnt+1;
	if(!cmp(x, y, cnt)) return;
	for(int dir = 0;dir < 4;dir++)
	{
		int newx = x + dx[dir], newy = y + dy[dir];
		if(valid(newx, newy, 'd'))
		{
			vis[newx][newy] = 1;
			dfs(newx, newy, cnt+1);
			vis[newx][newy] = 0;
		}
	}
	if(bfs(x, y) == 0 && cmp(x, y, cnt))
		memcpy(&ans, &temp, sizeof(temp));
}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
	while(scanf("%d%d", &r, &c) && r)
	{
		for(int i = 0;i < r;i++)
			scanf("%s", maze[i]);
		ans.clear();
		for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++)
			if(isdigit(maze[i][j]))
			{
				memset(vis, 0, sizeof(vis));
				temp.clear();
				vis[i][j] = 1;
				dfs(i, j, 0);
			}
		for(int i = 0;i < ans.len;i++)
			putchar(ans.num[i]);
		putchar('\n');
	}
	return 0;
}
