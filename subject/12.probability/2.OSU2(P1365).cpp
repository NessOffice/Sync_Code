#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char s[1000000];
int main()
{
	double x = 0, ans = 0;
	int n;
	scanf("%d%s", &n, s);
	for(int i = 0;i < n;i++)
	{
		double p;
		switch (s[i])
		{
			case 'o': p = 1;break;
			case '?': p = 0.5;break;
			case 'x': p = 0;break;
		}
		ans += p*(2*x + 1);
		x = p*(x + 1);
	}
	printf("%.4lf", ans);
	return 0;
}
