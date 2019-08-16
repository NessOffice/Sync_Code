#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
LL euclid(LL a, LL b)
{
	if(a < b) return euclid(b, a);
	return b == 0 ? a : euclid(b, a % b);
}
int main()
{
	LL A, B, C, D, ans = 0;
	scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
	for(LL son = 1;son < 1000;son++)
	{
		for(LL mom = 1;mom < 1000;mom++)
		{
			if(son + mom >= 1000) break;
			if(euclid(son, mom) != 1LL) continue;
			LL l, r;
			l = max((A-1)/son+1, (C-1)/mom+1);
			r = min(B / son, D / mom);
			if(l > r || r == 0) continue;
			ans += (r - l + 1);
		}
	}
	printf("%lld", ans);
	return 0;
}
/*
5 8 3 6

2018 2019 2018 2019
*/