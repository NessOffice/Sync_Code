#include <cstdio>
#include <algorithm>
const int maxn = 100000 + 10;
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int T, n, limit, w[maxn];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &limit);
		for(int i = 0;i < n;i++)
			scanf("%d", &w[i]);
		std::sort(w, w+n);
		int L, R, tot;
		L = tot = 0;
		R = n-1;
		while(L < R)
		{
			if(w[L] + w[R] <= limit) L++;
			R--, tot++;
		}
		if(L == R) tot++;
		printf("%d\n", tot);
		if(T) putchar('\n');
	}
	return 0;
}
