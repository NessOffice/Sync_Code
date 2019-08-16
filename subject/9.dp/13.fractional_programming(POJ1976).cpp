#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3+5;
const double eps = 1e-6;
int a[maxn], b[maxn];
struct Node{double val; int index;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.val > rhs.val;}
bool eq(double num1, double num2){return fabs(num1 - num2) < eps;}
int main()
{
	int n, k;
	while(1)
	{
		scanf("%d%d", &n, &k);
		if(n + k == 0) break;
		k = n - k;
		for(int i = 0;i < n;i++)
			scanf("%d", a + i);
		for(int i = 0;i < n;i++)
			scanf("%d", b + i);
		double l = 0.0;
		while(1)
		{
			for(int i = 0;i < n;i++)
			{
				nodes[i].val = a[i] - l*b[i];
				nodes[i].index = i;
			}
			sort(nodes, nodes + n, cmp);
			double p, q;
			p = q = 0.0;
			for(int i = 0;i < k;i++)
			{
				p += a[nodes[i].index];
				q += b[nodes[i].index];
			}
			double l_old = l;
			l = p / q;
			if(eq(l_old, l)) break;
		}
		printf("%.0lf\n", 100*l);
	}
	return 0;
}
