#include <cstdio>
#include <cstring>
typedef long long LL;
int main()
{
	LL T, n, m;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &m);
		LL ans = n/m*(m-1)+(n%m?n%m-1:0);
		ans = ans & 1;
		printf("%lld\n", ans ^ 1);
	}
	return 0;
}
