#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 10;
const int MAXM = 3e5 + 10;
int n, s;
double ans;
int x[MAXN], y[MAXN];
int pre[MAXN];
struct Edge{int from, to;double w;}G[MAXM];
int cnt, num_of_edge;
double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}
bool cmp(const Edge& lhs, const Edge& rhs)
{
	return lhs.w < rhs.w;
}
void add_edge(int u, int v, double w)
{
	G[cnt].to = v;
	G[cnt].from = u;
	G[cnt].w = w;
	cnt++;
}
void init()
{
	cnt = num_of_edge = 0;
	ans = 0.0;
	for(int i = 1;i <= n;i++)
		pre[i] = i;
}
int find(int u)
{
	int fu = pre[u];
	while(fu != pre[fu])
		fu = pre[fu];
	return pre[u] = fu;
}
void krustral()
{
	sort(G, G+cnt, cmp);
	for(int i = 0;i < cnt;i++)
	{
		int fu = find(G[i].from),
		    fv = find(G[i].to);
		if(fu != fv)
		{
			ans = max(ans, G[i].w);
			pre[fv] = fu;
			num_of_edge++;
		}
		if(num_of_edge == n-s)
			return;
	}
}
int main()
{
	scanf("%d%d", &s, &n);
	init();
	if(s == 0) s = 1; // special case
	for(int i = 1;i <= n;i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		for(int j = 1;j < i;j++)
		{
			double w = dist(x[i], y[i], x[j], y[j]);
			add_edge(i, j, w);
		}
	}
	krustral();
	printf("%.2lf\n", ans);
	return 0;
}
