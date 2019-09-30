#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	LL a, b;
	scanf("%lld%lld", &a, &b);
	if(a > b) swap(a, b);
	double phi = (sqrt(5) + 1) / 2;
	LL k = (a + 1) / phi;
	LL ans = (b == (LL)(k*phi*phi) ? 0 : 1);
	printf("%lld", ans);
	return 0;
}
