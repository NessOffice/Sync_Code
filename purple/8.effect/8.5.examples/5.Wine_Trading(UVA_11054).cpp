#include <cstdio>
typedef long long LL;
LL abs(LL a){return a > 0 ? a : -a;}
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	LL n, demand, ans, last;
	while(scanf("%lld", &n) && n)
	{
		ans = last = 0;
		while(n--)
		{
			scanf("%lld", &demand);
			ans += abs(last);
			last += demand;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
