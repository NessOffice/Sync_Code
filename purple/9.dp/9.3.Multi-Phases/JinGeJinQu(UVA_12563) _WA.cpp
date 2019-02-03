#include <cstdio>
#include <cstring>
const int maxn = 10000 + 10;
int max(int a, int b){return a > b ? a : b;}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, n, t, dpn[maxn], dpt[maxn];
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d%d", &n, &t);
		memset(dpn, 0, sizeof(dpn));
		memset(dpt, 0, sizeof(dpt));
		while(n--)
		{
			int w;
			scanf("%d", &w);
			for(int j = t-1;j >= w;j--)
			if(dpn[j-w] + 1 >= dpn[j])
				dpn[j] = max(dpn[j], dpn[j-w] + 1),
				dpt[j] = max(dpt[j], dpt[j-w] + w);
		}
		printf("Case %d: %d %d\n", kase, dpn[t-1]+1, dpt[t-1]+678);
	}
	return 0;
}
