#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
struct Region{double L, R;}regions[maxn];
bool cmp(Region& lhs, Region& rhs){return lhs.R < rhs.R;}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int s, D, n, x, y;
	while(~scanf("%d", &s))
	{
		scanf("%d%d", &D, &n);
		for(int i = 0;i < n;i++)
		{
			double dx;
			scanf("%d%d", &x, &y);
			dx = sqrt(D*D-y*y);
			regions[i].L = max(0.0, x-dx);
			regions[i].R = min(s*1.0, x+dx);
		}
		sort(regions, regions + n, cmp);
		int cnt = 0, i = 0;
		double last = -1;
		while(i < n)
		{
			cnt++, last = regions[i].R;
			while(i < n && last >= regions[i].L) i++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
