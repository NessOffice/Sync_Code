#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 210;
int n = 0;
struct Matrix // caution!!! Only for this problem
{
	int a[maxn+1][maxn+1];
	int r, c;
	Matrix(int r, int c):r(r), c(c){memset(a, 0x3f, sizeof(a));}
	Matrix operator* (const Matrix& rhs) const{
		Matrix res = Matrix(n, n);
		for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				res.a[i][j] = min(res.a[i][j], a[i][k] + rhs.a[k][j]);
		return res;
	}
};
int loc[2100];
int main()
{
	Matrix base = Matrix(maxn, maxn);
	Matrix ans = Matrix(maxn, maxn);
	int k, m, st, ed;
	scanf("%d%d%d%d", &k, &m, &st, &ed);
	while(m--)
	{
		int u, v, d;
		scanf("%d%d%d", &d, &u, &v);
		if(!loc[u]) loc[u] = ++n;
		if(!loc[v]) loc[v] = ++n;
		base.a[loc[u]][loc[v]] = base.a[loc[v]][loc[u]] = min(base.a[loc[u]][loc[v]], d);
	}
	for(int i = 1;i <= n;i++)
		ans.a[i][i] = 0;
	while(k)
	{
		if(k & 1)
			ans = ans * base;
		k >>= 1;
		base = base * base;
	}
	printf("%d", ans.a[loc[st]][loc[ed]]);
	return 0;
}
