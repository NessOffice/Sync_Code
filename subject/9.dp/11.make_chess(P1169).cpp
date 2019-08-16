#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register
using namespace std;
typedef long long LL;
const int maxn = 2e3+5;
int lft[maxn][maxn], rgt[maxn][maxn], up[maxn][maxn], grids[maxn][maxn];
int main()
{
	int n, m, ans1 = 0, ans2 = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	{
		scanf("%d", &grids[i][j]);
		lft[i][j] = rgt[i][j] = j;
		up[i][j] = i;
	}
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
		if(j && grids[i][j-1] != grids[i][j])
			lft[i][j] = lft[i][j-1];
	for(int i = 0;i < n;i++)
	for(int j = m-1;j >= 0;j--)
		if(j != m-1 && grids[i][j+1] != grids[i][j])
			rgt[i][j] = rgt[i][j+1];
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	{
		int w = 1, h = 1, a = 1;
		if(i && grids[i-1][j] != grids[i][j])
		{
			lft[i][j] = max(lft[i-1][j], lft[i][j]);
			rgt[i][j] = min(rgt[i-1][j], rgt[i][j]);
			up[i][j] = up[i-1][j];
		}
		w = rgt[i][j] - lft[i][j] + 1;
		h = i - up[i][j] + 1;
		a = min(w, h);
		ans1 = max(ans1, a*a);
		ans2 = max(ans2, w*h);
	}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
