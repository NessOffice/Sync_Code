#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+1;
LL ans[maxn];
int main()
{
	for(LL q = 1;q <= maxn;q++)
	{
		LL lst = 1, sum = 1;
		while(1)
		{
			lst *= q;
			sum += lst;
			if(sum >= maxn) break;
			else ans[sum]++;
		}
	}
	LL n, res = 0;
	scanf("%lld", &n);
	for(LL a = 1;a <= n;a++)
	{
		if(n % a) continue;
		res += ans[n / a];
	}
	printf("%lld", res);
	return 0;
}
