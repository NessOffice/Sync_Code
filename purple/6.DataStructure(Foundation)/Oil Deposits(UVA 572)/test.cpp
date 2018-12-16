#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
char grid[maxn][maxn];
int d[maxn][maxn], cnt, n, m;
bool dfs(int i, int j)
{
	if(i < 0 || i>= n || j < 0 || j>= m) return false;
	if(d[i][j] >= 0 || grid[i][j] != '@') return false;
	d[i][j] = cnt;
	for(int i0 = -1;i0 <= 1;i0++)
		for(int j0 = -1;j0 <= 1;j0++)
			dfs(i + i0, j + j0);
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d", &n, &m) && n)
	{
		memset(d, -1, sizeof(d)), cnt = 0;
		for(int i = 0;i < n;i++) scanf("%s", grid + i);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if(dfs(i, j)) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
