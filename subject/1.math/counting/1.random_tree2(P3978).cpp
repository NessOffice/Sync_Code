#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	double n;
	scanf("%lf", &n);
	printf("%.12lf", n*(n+1.0)/(2.0*n-1.0)/2.0);
	return 0;
}
