#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int rd(){int x;scanf("%d", &x);return x;}
int cnt_of_set_of_dis, set_of_dis[maxn], judge[maxn], query[maxn], ans[maxn];
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
	set_of_dis[cnt_of_set_of_dis++] = dis[u];
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		dis[v] = dis[u] + weigh[i];
		get_dis(v, u);
	}
}
int q[maxn], sz_of_q;
void calc(int u)
{
	sz_of_q = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v]) continue;
		cnt_of_set_of_dis = 0;
		dis[v] = weigh[i];
		get_dis(v, u);

		for(int j = 0;j < cnt_of_set_of_dis;j++)
		for(int k = 0;k < m;k++)
			if(query[k] >= set_of_dis[j])
				ans[k] |= judge[query[k]-set_of_dis[j]];

		for(int j = 0;j < cnt_of_set_of_dis;j++)
			q[sz_of_q++] = set_of_dis[j],
			judge[set_of_dis[j]] = 1;
	}
	for(int i = 0;i < sz_of_q;i++)
		judge[q[i]] = 0;
}
void solve(int u)
{
	vis[u] = judge[0] = 1;
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
	n = rd();m = rd();
	for(int i = 0;i < n-1;i++)
	{
		int u = rd(), v = rd(), w = rd();
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for(int i = 0;i < m;i++)
		query[i] = rd();
	maxp[root=0] = sum = n;
	get_root(1, 0);
	solve(root);

	for(int i = 0;i < m;i++)
		printf("%s\n", ans[i] ? "AYE" : "NAY");
	return 0;
}
