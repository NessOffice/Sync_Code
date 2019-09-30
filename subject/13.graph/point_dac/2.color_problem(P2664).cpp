#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5+5;
int rd(){int x;scanf("%d", &x);return x;}
int color[maxn], c2cnt_node[maxn], n2cnt_color[maxn], n2cnt_color_temp, node2fst[maxn], cnt_of_color[maxn]; // c for color, n for node
LL ans_part2, ans[maxn];
int n, m, sum, root, vis[maxn], sz[maxn], maxp[maxn];
int head[maxn<<1], nxt[maxn<<1], to[maxn<<1], cnt_of_edge;
void add_edge(int u, int v)
{
	cnt_of_edge++;
	to[cnt_of_edge] = v;
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
void get_info(int u, int fa, int rt)
{
	sz[u] = 1;
	if(++cnt_of_color[color[u]] == 1)
		node2fst[u] = 1, n2cnt_color_temp++;
	else
		node2fst[u] = 0;
	n2cnt_color[u] = n2cnt_color_temp;
	ans[rt] += n2cnt_color_temp;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		get_info(v, u, rt);
		sz[u] += sz[v];
	}
	if(node2fst[u])
		c2cnt_node[color[u]] += sz[u], ans_part2 += sz[u], n2cnt_color_temp--;
	cnt_of_color[color[u]]--;
}
void change(int u, int fa, int flag)
{
	if(node2fst[u])
		c2cnt_node[color[u]] += flag * sz[u], ans_part2 += flag * sz[u];
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		change(v, u, flag);
	}
}
void calc(int u, int fa, int cnt_of_node)
{
	if(node2fst[u]) ans_part2 -= c2cnt_node[color[u]];
	ans[u] += 1LL * n2cnt_color[u] * cnt_of_node + ans_part2;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		calc(v, u, cnt_of_node);
	}
	if(node2fst[u]) ans_part2 += c2cnt_node[color[u]];
}
void clear(int u, int fa)
{
	c2cnt_node[color[u]] = 0;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v] || v == fa) continue;
		clear(v, u);
	}
}
void solve(int u)
{
	vis[u] = 1;
	get_info(u, 0, u);
	c2cnt_node[color[u]] -= sz[u], ans_part2 -= sz[u];
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(vis[v]) continue;
		change(v, u, -1);
		calc(v, u, sz[u]-sz[v]);
		change(v, u, 1);
	}
	clear(u, 0);
	ans_part2 = 0;
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
	for(int i = 1;i <= n;i++)
		color[i] = rd();
	for(int i = 0;i < n-1;i++)
	{
		int u = rd(), v = rd();
		add_edge(u, v);
		add_edge(v, u);
	}
	maxp[root=0] = sum = n;
	get_root(1, 0);
	solve(root);

	for(int i = 1;i <= n;i++)
		printf("%lld\n", ans[i]);
	return 0;
}
