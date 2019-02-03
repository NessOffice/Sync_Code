//Accepted 930ms
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
const int maxs = 16 + 4;
const int maxn = 200 + 5;
const int dx[] = {1, -1, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0};
int target[3], start[3], deg[maxn], G[maxn][5], d[maxn][maxn][maxn];
int ID(int a, int b, int c){return (a<<16)|(b<<8)|c;}
bool conflict(int a, int b, int a2, int b2){return a2 == b2 || (a == b2 && b == a2);}
int solve()
{
	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(ID(start[0], start[1], start[2]));
	d[start[0]][start[1]][start[2]] = 0;
	while(!q.empty())
	{
		int node = q.front();q.pop();
		int a = (node>>16)&0xff, b = (node>>8)&0xff, c = node&0xff;
		if(a == target[0] && b == target[1] && c == target[2]) return d[a][b][c];
		for(int i = 0;i < deg[a];i++)
		{
			int a2 = G[a][i];
			for(int j = 0;j < deg[b];j++)
			{
				int b2 = G[b][j];
				if(conflict(a, b, a2, b2)) continue;
				for(int k = 0;k < deg[c];k++)
				{
					int c2 = G[c][k];
					if(conflict(a, c, a2, c2)) continue;
					if(conflict(b, c, b2, c2)) continue;
					if(d[a2][b2][c2] != -1) continue;
					d[a2][b2][c2] = d[a][b][c] + 1;
					q.push(ID(a2, b2, c2));
				}
			}
		}
	}
	return -1;
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int row, col, ghosts;
	while(scanf("%d%d%d\n", &col, &row, &ghosts), row)
	{
		char maze[maxs][maxs];
		for(int i = 0;i < row;i++)
			fgets(maze[i], maxs, stdin);
		int cnt = 0, id[maxs][maxs], x[maxn], y[maxn];
		for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
			if(maze[i][j] != '#')
			{
				x[cnt] = i, y[cnt] = j;
				if(islower(maze[i][j])) start[maze[i][j] - 'a'] = cnt;
				else if(isupper(maze[i][j])) target[maze[i][j] - 'A'] = cnt;
				id[i][j] = cnt++;
			}
		for(int i = 0;i < cnt;i++)
		{
			deg[i] = 0;
			for(int dir = 0;dir < 5;dir++)
			{
				int newx = x[i] + dx[dir], newy = y[i] + dy[dir];
				if(maze[newx][newy] != '#')
					G[i][deg[i]++] = id[newx][newy];
			}
		}
		if(ghosts <= 2) deg[cnt] = 1, G[cnt][0] = cnt, start[2] = target[2] = cnt++;
		if(ghosts <= 1) deg[cnt] = 1, G[cnt][0] = cnt, start[1] = target[1] = cnt++;
		printf("%d\n", solve());
	}
	return 0;
}
