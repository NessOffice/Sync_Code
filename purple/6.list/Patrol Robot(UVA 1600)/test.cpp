#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 20 + 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int cell[maxn][maxn], energy[maxn][maxn];
int d[maxn][maxn], vis[maxn][maxn];
int T, m, n, k;
bool invalid(int x, int y)
{
	if(x < 1 || x > m) return true;
	if(y < 1 || y > n) return true;
	return false;
}
void mazeBFS()
{
	d[1][1] = 0;
	energy[1][1] = k;
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;q.pop();
		for(int dir = 0;dir < 4;dir++)
		{
			int x1 = x + dx[dir];
			int y1 = y + dy[dir];
			if(invalid(x1, y1) || vis[x1][y1]) continue;
			if(cell[x1][y1]) energy[x1][y1] = energy[x][y] - 1;
			else energy[x1][y1] = k;
			if(energy[x1][y1] < 0) continue;
			d[x1][y1] = d[x][y] + 1;
			vis[x1][y1] = 1;
			q.push(make_pair(x1, y1));
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &m, &n, &k);
		for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			scanf("%d", &cell[i][j]);
			d[i][j] = -1, vis[i][j] = 0;
		}
		mazeBFS();
		printf("%d\n", d[m][n]);
	}
	return 0;
}
