#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
LL calc(LL m)
{
	LL ans = 0;
	for(LL i = 1LL;i <= sqrt(m);i++)
	{
		if(m % i) continue;
		if(i*i == m) ans++;
		else ans += 2LL;
	}
	return ans;
}
int main()
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	LL n;
	scanf("%lld", &n);
	LL ans = 1LL;
	for(LL i2 = 1LL;i2 <= sqrt(n);i2++)
	{
		if(n % i2) continue;
		ans += calc(i2 - 1LL) + calc(n / i2 - 1LL);
		if((i2)*(i2) == n) ans -= calc(i2-1LL);
	}
	printf("%lld\n", ans);
	return 0;
}
