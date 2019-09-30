#include <cstdio>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 505;
const int maxm = 5e5+5; // 500 * 500 * 2
const double EPS = 1e-10; // ???????
double G[maxn][maxn], E[maxm];
int head[maxn], sz[maxn], cnt_of_edge;
struct Edge{int from, to, nxt;}edges[maxm];
int n, m;
bool eq(double a, double b){return fabs(a - b) < EPS;}
void add_edge(int u, int v)
{
	cnt_of_edge++;
	edges[cnt_of_edge].from = u;
	edges[cnt_of_edge].to = v;
	edges[cnt_of_edge].nxt = head[u];
	head[u] = cnt_of_edge;
	sz[u]++;
}
void build()
{
	for(int i = 1;i <= n;i++) // caution
	for(int j = 1;j <= n;j++)
		G[i][j] = 0;
	G[1][n] = 1;
	for(int u = 1;u < n;u++)
	{
		G[u][u] = 1.0;
		for(int i = head[u];i;i = edges[i].nxt)
		{
			int v = edges[i].to;
			if(v == n) continue;
			G[u][v] = -1.0 / sz[v];
		}
	}
}
void gauss()
{
	for(int i = 1;i < n;i++)
	{
        int mx = i;
		for(int j = i+1;j < n;j++)
			if(fabs(G[j][i]) > fabs(G[mx][i]))
				mx = j;
        if(i != mx)
			for(int k = 1;k <= n;k++)
				swap(G[i][k], G[mx][k]);
		double mul = G[i][i];
        for(int k = i;k <= n;k++)
			G[i][k] /= mul;
        for(int j = 1;j < n;j++)
		{
			if(j == i || eq(G[j][i], 0))
				continue;
			double mul = G[j][i];
			for(int k = i;k <= n;k++)
				G[j][k] -= mul * G[i][k];
        }
    }
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	build();
	gauss();
	double ans = 0;
	for(int i = 1;i < cnt_of_edge;i += 2)
	{
		int u = edges[i].from, v = edges[i].to;
		if(u != n) E[i / 2] += G[u][n] / sz[u];
		if(v != n) E[i / 2] += G[v][n] / sz[v];
	}
	sort(E, E + m, greater<double>());
	for(int i = 0;i < m;i++)
		ans += E[i] * (i+1);
	printf("%.3lf", ans);
	return 0;
}
