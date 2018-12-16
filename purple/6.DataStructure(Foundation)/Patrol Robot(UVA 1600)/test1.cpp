#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 20 + 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int cell[maxn][maxn];
int d[maxn][maxn][maxn], vis[maxn][maxn][maxn];
int T, m, n, k;
struct Cell{
	int x, y, energy;
	Cell(int x, int y, int energy):x(x), y(y), energy(energy){}
};
bool invalid(int x, int y)
{
	if(x < 1 || x > m) return true;
	if(y < 1 || y > n) return true;
	return false;
}
void mazeBFS()
{
	d[1][1][k] = 0, vis[1][1][k] = 1;
	queue<Cell> q;
	Cell begin = Cell(1, 1, k);
	q.push(begin);
	while(!q.empty())
	{
		Cell c = q.front();q.pop();
		int x = c.x, y = c.y, e0 = c.energy;
		for(int dir = 0;dir < 4;dir++)
		{
			int x1 = x + dx[dir];
			int y1 = y + dy[dir];
			int e1 = c.energy;
			if(invalid(x1, y1)) continue;
			if(cell[x1][y1]) e1--;
			else e1 = k;
			if(e1 < 0 || vis[x1][y1][e1]) continue;
			d[x1][y1][e1] = d[x][y][e0] + 1;
			vis[x1][y1][e1] = 1;
			q.push(Cell(x1, y1, e1));
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d", &T);
	while(T--)
	{
		memset(d, -1, sizeof(d));
		memset(vis, 0, sizeof(vis));
		scanf("%d %d %d", &m, &n, &k);
		for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d", &cell[i][j]);
		mazeBFS();
		int ans = -1;
		for(int i = 0;i <= k;i++)
			if(d[m][n][i] >= 0 && (ans == -1 || ans > d[m][n][i]))
				ans = d[m][n][i];
		printf("%d\n", ans);
	}
	return 0;
}
