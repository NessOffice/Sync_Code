#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int UPPER = 1e7;
double my_sqrt(double target)
{
	int cnt = 1;
	double r = target-1;
	while(cnt < 6 && r*r > target)
	{
		r = (r + target / r) / 2.0;
		cnt++;
	}
//	while(l < r)
//	{
//		int mid = l + r + 1 >> 1;
//		if(1LL*mid*mid > target)
//			r = mid - 1;
//		else
//			l = mid;
//	}
	return r;
}
struct Nmsl{int nm;}nmsl[3];
int main()
{
	int nm[] = {1, 3, 5};
	sort(nm, nm + 3);
	clock_t begin, end;
	begin = clock();
	for(int i = 0;i < UPPER;i++)
		double a = sqrt(1.0*i);
	end = clock();
	printf("sqrt time: %.4lf\n", (double)(end-begin)/CLOCKS_PER_SEC);
	begin = clock();
	for(int i = 0;i < UPPER;i++)
		double a = my_sqrt(1.0*i);
	end = clock();
	printf("log time: %.4lf\n", (double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}
