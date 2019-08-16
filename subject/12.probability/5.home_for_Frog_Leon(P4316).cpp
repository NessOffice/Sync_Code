#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5; // caution
const double EPS = 1e-8;
double E[maxn];
int head[maxn], to[maxn], weigh[maxn], nxt[maxn], sz[maxn], cnt_of_edge;
int n, m;
bool eq(double a, double b){return fabs(a - b) < EPS;}
void add_edge(int u, int v, int w)
{
	cnt_of_edge++;
	to[cnt_of_edge] = v;
	weigh[cnt_of_edge] = w;
	nxt[cnt_of_edge] = head[u];
	head[u] = cnt_of_edge;
	sz[u]++;
}
double calc(int u)
{
	if(u == n) return 0.0; // end
	if(sz[u] == 0) return E[u] = -0.8; // dead
	if(E[u] > -0.9) return E[u]; // visited
	double ans = 0;
	for(int i = head[u];i;i = nxt[i])
		if(calc(to[i]) > -0.5) // capable to reach the end
			ans += ((calc(to[i]) + 1.0*weigh[i]) / (1.0*sz[u]));
	return E[u] = ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		E[i] = -1.0;
	for(int i = 1;i <= m;i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	printf("%.2lf", calc(1));
	return 0;
}
/*
2 1
1 2 2

3 1
1 2 2

3 2
1 2 2
1 3 2

4 4 
1 2 1 
1 3 2 
2 3 3 
3 4 4

*/