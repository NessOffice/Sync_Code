#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int rd(){int x;scanf("%d", &x);return x;}
int cnt_of_dis[2][3], ans;
int n, m, sum, root, vis[maxn], sz[maxn], dis[maxn], maxp[maxn];
int head[maxn], nxt[maxn], to[maxn], weigh[maxn], cnt_of_edge;
void add_edge(int u, int v, int w)
{
	cnt_of_edge++;
	to[cnt_of_edge] = v;
	weigh[cnt_of_edge] = w;
	nxt[cnt_of_edge] = head[u];
	head[u] = cnt_of_edge;
}
void get_root(int u, int fa)
{
	sz[u] = 1, maxp[u] = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		get_root(v, u);
		sz[u] += sz[v];
		maxp[u] = max(maxp[u], sz[v]);
	}
	maxp[u] = max(maxp[u], sum-sz[u]);
	if(maxp[u] < maxp[root]) root = u;
}
void get_dis(int u, int fa)
{
	cnt_of_dis[1][dis[u]]++;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		dis[v] = (dis[u] + weigh[i]) % 3;
		get_dis(v, u);
	}
}
void calc(int u)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v]) continue;
		cnt_of_dis[1][0] = cnt_of_dis[1][1] = cnt_of_dis[1][2] = 0;
		dis[v] = weigh[i];
		get_dis(v, u);

		ans += 2*cnt_of_dis[1][0] * cnt_of_dis[0][0];
		ans += 2*cnt_of_dis[1][1] * cnt_of_dis[0][2];
		ans += 2*cnt_of_dis[1][2] * cnt_of_dis[0][1];

		cnt_of_dis[0][0] += cnt_of_dis[1][0];
		cnt_of_dis[0][1] += cnt_of_dis[1][1];
		cnt_of_dis[0][2] += cnt_of_dis[1][2];
	}
	ans += 2*cnt_of_dis[0][0];
	cnt_of_dis[0][0] = cnt_of_dis[0][1] = cnt_of_dis[0][2] = 0;
}
void solve(int u)
{
	vis[u] = 1;
	calc(u);
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v]) continue;
		sum = sz[v], maxp[root=0] = n;
		get_root(v, 0);
		solve(root);
	}
}
int main()
{
	n = rd();
	for(int i = 0;i < n-1;i++)
	{
		int u = rd(), v = rd(), w = rd() % 3;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	maxp[root=0] = sum = n;
	get_root(1, 0);
	solve(root);

	ans += n; // the ones that hadn't been calculated, for example, (1, 1)
	int d = __gcd(ans, n*n);
	printf("%d/%d\n", ans/d, n*n/d);
	return 0;
}
