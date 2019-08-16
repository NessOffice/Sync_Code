#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
LL num[2][maxn<<1], l[2][maxn], r[2][maxn];
LL ABS(LL x){return x < 0 ? -x : x;}
int main()
{
	LL T;
	scanf("%lld", &T);
	while(T--)
	{
		LL n, target, ans = 0;
		scanf("%lld", &n);
		for(int i = 0;i < n;i++)
		{
			scanf("%lld%lld%lld%lld", &num[0][i<<1], &num[1][i<<1], &num[0][i<<1|1], &num[1][i<<1|1]);
			l[0][i] = num[0][i<<1], r[0][i] = num[0][i<<1|1];
			l[1][i] = num[1][i<<1], r[1][i] = num[1][i<<1|1];
		}
		for(int i = 0;i < 2;i++)
		{
			sort(num[i], num[i] + 2*n);
			target = num[i][n];
			for(int j = 0;j < n;j++)
				ans += ((ABS(l[i][j] - target) + ABS(r[i][j] - target) - ABS(r[i][j] - l[i][j])) / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1
2
2 2 3 3
4 4 5 5
*/