#include <cstdio>
#include <cmath>
#include <algorithm>
const int maxn = 1e5 + 5;
const double eps = 1e-10;
struct Node{int l, r;}a[maxn];
bool cmp(Node& lhs, Node& rhs){return lhs.l < rhs.l;}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0;i < n;i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		std::sort(a, a+n, cmp);
		double r = 1e6, l = 0, ans = 0;
		while(r-l > eps)
		{
			bool ok = true;
			double s = 0, m = (r+l)/2.0;
			for(int i = 0;i < n && ok;i++)
			{
				if(s < a[i].l) s = a[i].l;
				if(s+m > a[i].r) ok = false;
				s += m;
			}
			if(ok) l = m;
			else r = m;
		}
		ans = l;
		int rp = 0, rq = 1;
		for(int p = 0, q = 1;q <= n;q++)
		{
			p = round(q*ans);
			if(fabs(1.0*p/q-ans) < fabs(1.0*rp/rq-ans))
				rp = p,
				rq = q;
		}
		printf("%d/%d\n", rp, rq);
	}
	return 0;
}
