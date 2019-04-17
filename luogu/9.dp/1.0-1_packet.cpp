#include <cstdio>
#include <algorithm>
using namespace std;
int f[30010];
int v[30], w[30];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++)
		scanf("%d%d", &v[i], &w[i]);
	for(int i = 0;i < m;i++)
		for(int j = n;j >= v[i];j--)
			f[j] = max(f[j], f[j-v[i]] + v[i]*w[i]);
	printf("%d\n", f[n]);
	return 0;
}
