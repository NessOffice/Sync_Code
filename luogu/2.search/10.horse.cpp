#include <cstdio>
#include <cstring>
int n, m, qx[410*410], qy[410*410], d[410][410];
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
bool valid(int x, int y){return (0 < x && x <= n) && (0 < y && y <= m);}
void bfs(int x, int y)
{
	int head = 0, tail = 1;
	qx[head] = x;
	qy[head] = y;
	while(head < tail)
	{
		x = qx[head];
		y = qy[head++];
		for(int i = 0;i < 8;i++)
		{
			int newx = x+dx[i];
			int newy = y+dy[i];
			if(!valid(newx, newy)) continue;
			if(d[newx][newy] == -1)
			{
				d[newx][newy] = d[x][y] + 1;
				qx[tail] = newx;
				qy[tail++] = newy;
			}
		}
	}
}
int main()
{
	memset(d, -1, sizeof(d));
	int sx, sy;
	scanf("%d%d%d%d", &n, &m, &sx, &sy);
	d[sx][sy] = 0;
	bfs(sx, sy);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			printf("%-5d", d[i][j]);
		printf("\n");
	}
	return 0;
}