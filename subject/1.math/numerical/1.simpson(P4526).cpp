#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define mid (l+r)/2
const double eps = 1e-12; // -8->WA
double a;
double eq(double x, double y){return fabs(x-y) < eps;}
double f(double x)
{
	return pow(x, a/x-x);
}
double integral(double l, double r)
{
	return (f(l)+4*f(mid)+f(r))*(r-l)/6;
}
double simpson(double l, double r)
{
	double ans = integral(l, r), ans_l = integral(l, mid), ans_r = integral(mid, r);
	if(eq(ans, ans_l + ans_r)) return ans;
	return simpson(l, mid) + simpson(mid, r);
}
int main()
{
	scanf("%lf", &a);
	if(a < 0) printf("orz");
	else printf("%.5lf\n", simpson(1e-20, 15));
	return 0;
}
