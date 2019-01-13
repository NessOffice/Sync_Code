#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
const double Width = 1000.0;
int n, vis[maxn];
double x[maxn], y[maxn], r[maxn], in, out;
bool ok;
bool intersect(int u, int v)
{
	return (((x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v])) < (r[u] + r[v])*(r[u] + r[v]));
}
void checkBorder(int u)
{
	if(x[u] <= r[u])
		in = min(in, y[u] - sqrt(r[u]*r[u] - x[u]*x[u]));
	if(x[u] + r[u] >= Width)
		out = min(out, y[u] - sqrt(r[u]*r[u] - (Width-x[u])*(Width-x[u])));
}
void crossDFS(int u)
{
	if(vis[u] || !ok) return;
	vis[u] = 1;
	if(y[u] <= r[u]) ok = false;
	for(int v = 0;v < n;v++)
		if(intersect(u, v)) crossDFS(v);
	checkBorder(u);//为何它可以保证正确答案？这是很有意思的
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d", &n) == 1)
	{
		in = out = Width;
		ok = true;
		for(int i = 0;i < n;i++) vis[i] = 0;
		for(int i = 0;i < n;i++)
			scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
		for(int u = 0;u < n && ok;u++)
			if(y[u] + r[u] >= Width) crossDFS(u);
		if(ok) printf("0.00 %.2lf %.2lf %.2lf\n", in, Width, out);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
