#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	double a[8], sum = 0, ans = 1;
	for(int i = 1;i <= 7;i++)
		scanf("%lf", a+i),
		sum += a[i];
	if(sum <= 6.9) // CAUTION!!!
	{
		printf("%.3lf", ans = 0);
		return 0;
	}
	for(int i = 1;i <= 7;i++)
	{
		ans *= (1.0*i); // 7!
		ans *= a[i];
		ans /= (sum - i + 1);
	}
	ans *= (sum - 6); // E(\sum X) = \sum E(X)
	printf("%.3lf", ans);
	return 0;
}
