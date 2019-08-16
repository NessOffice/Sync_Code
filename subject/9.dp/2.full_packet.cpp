#include <cstdio>
#include <algorithm>
using namespace std;
int f[30010];
int v[30], w[30];
int main()
{
	int n, m, w, v, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d", &w, &v);
		for(int j = w;j <= n;j++)
		{
			f[j] = max(f[j], f[j-w] + w*v);
			ans = max(ans, f[j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
