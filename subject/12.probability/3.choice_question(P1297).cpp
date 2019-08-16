#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	int n, A, B, C, fst, lst, now, now2;
	double ans = 0;
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &fst);
	for(int i = 1;i <= n;i++)
	{
		if(i >= 2)
			now = ((LL)now * A + B) % 100000001;
		else
			now = fst;
		now2 = now % C + 1;
		if(i >= 2)
			ans += (1.0 / max(now2, lst));
		lst = now2;
	}
	fst = fst % C + 1;
	ans += (1.0 / max(now2, fst));
	printf("%.3lf", ans);
	return 0;
}
