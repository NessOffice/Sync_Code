#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;
int n = 5e6;
double a, b, c, d, R, dx, x, ans = 0;
double f(double x)
{
	return (c*x+d)/(a*x+b);
}
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &x, &R);
	dx = (R - x) / n;
	for(int i = 0;i <= n;i++, x += dx)
	{
		int k;
		if(i == 0 || i == n) k = 1;
		else if(i & 1) k = 4;
		else k = 2;
		ans += k*f(x);
	}
	ans = ans * dx / 3.0;
	printf("%.6lf", ans);
	return 0;
}
