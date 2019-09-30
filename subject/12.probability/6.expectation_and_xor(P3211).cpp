#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxm = 2e4+5; // caution
const double EPS = 1e-8;
double G[maxn][maxn];
int head[maxn], sz[maxn], cnt_of_edge;
struct Edge{int to, nxt, weigh;}edges[maxm];
int n, m;
bool eq(double G, double b){return fabs(G - b) < EPS;}
void add_edge(int u, int v, int w)
{
	cnt_of_edge++;
	edges[cnt_of_edge].to = v;
	edges[cnt_of_edge].weigh = w;
	edges[cnt_of_edge].nxt = head[u];
	head[u] = cnt_of_edge;
	sz[u]++;
}
void build(int mask)
{
	for(int i = 1;i <= n+1;i++) // caution
	for(int j = 1;j <= n+1;j++)
		G[i][j] = 0;
	G[n][n] = 1;
	for(int u = 1;u < n;u++)
	{
		G[u][u] = sz[u];
		for(int i = head[u];i;i = edges[i].nxt)
		{
			int v = edges[i].to;
			if(edges[i].weigh & mask) G[u][v]++, G[u][n+1]++;
			else G[u][v]--;
		}
	}
}
double gauss() // return the expectation from start to end
{
	for(int i = 1;i <= n;i++)
	{
        int mx = i;
        while(eq(G[mx][i], 0)) mx++;
        if(i != mx)
			for(int k = 1;k <= n;k++)
				swap(G[i][k], G[mx][k]);
		double mul = G[i][i];
        for(int k = i;k <= n+1;k++) G[i][k] /= mul;
        for(int j = 1;j <= n;j++)
		{
			if(j == i || eq(G[j][i], 0)) continue;
			double mul = G[j][i];
			for(int k = i;k <= n+1;k++)
				G[j][k] -= mul * G[i][k];
        }
    }
	return G[1][n+1];
}
int main()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		if(u != v) add_edge(v, u, w); // caution!!!
	}
	double ans = 0;
	for(int i = 0;i < 31;i++)
	{
		int mask = 1 << i;
		build(mask);
		ans += (gauss() * mask);
	}
	printf("%.3lf\n", ans);
	return 0;
}
