#include <cstdio>
const int maxn = 1e3 + 5;
int T, n, res, a[maxn], b[maxn];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", a + i);
			b[i] = a[i] - a[i-1];
		}
		res = 0;
		for(int i = n;i >= 1;i -= 2)
			res ^= b[i];
		printf("%s\n", res ? "TAK" : "NIE");
	}
	return 0;
}
