#include <cstdio>
#include <algorithm>
const int maxn = 100000 + 10;
int main()
{
	int T, n, limit, w[maxn];
	scanf("%d%d", &limit, &n);
	for(int i = 0;i < n;i++)
		scanf("%d", &w[i]);
	std::sort(w, w+n);
	int L, R, tot;
	L = tot = 0;
	R = n-1;
	while(L <= R)
	{
		if(w[L] + w[R] <= limit) L++;
		R--, tot++;
	}
	printf("%d\n", tot);
	return 0;
}
