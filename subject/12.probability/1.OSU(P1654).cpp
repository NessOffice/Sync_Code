#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x, x2, ans;
// x[i] for the expection of the number of contious "1"s in the tail
int main()
{
	x = x2 = ans = 0.0;
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		double p;
		scanf("%lf", &p);
		ans += p*(3*x2 + 3*x + 1);
		x2 = p*(x2 + 2*x + 1);
		x = p*(x + 1);
	}
	printf("%.1lf", ans);
	return 0;
}
