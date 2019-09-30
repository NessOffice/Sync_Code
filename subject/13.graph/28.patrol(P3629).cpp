#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5; // caution
int cnt, head[maxn], from[maxn], to[maxn], nxt[maxn], weigh[maxn], parent[maxn], depth[maxn];
int n, k;
void add_edge(int u, int v)
{
	cnt++;
	from[cnt] = u;
	to[cnt] = v;
	nxt[cnt] = head[u];
	weigh[cnt] = 1;
	head[u] = cnt;
}
void dfs(int u, int fa, int d)
{
	parent[u] = fa;
	depth[u] = d;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u, d+1);
	}
}
int find_endpoint()
{
	int node = 1;
	for(int u = 1;u <= n;u++)
		if(depth[u] > depth[node])
			node = u;
	return node;
}
int diameter2, dp[maxn];
void calc_dp(int u, int fa)
{
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v == fa) continue;
		calc_dp(v, u);
		diameter2 = max(diameter2, dp[u] + dp[v] + weigh[i]);
		dp[u] = max(dp[u], dp[v] + weigh[i]);
	}
}
bool mark[maxn];
int solve()
{
	dfs(1, 0, 0);
	int root = find_endpoint();
	dfs(root, 0, 0);
	int endpoint = find_endpoint();
	int diameter1 = depth[endpoint];
	if(k == 1) return 2*(n-1)-diameter1+1;

	// if k == 2
	for(int u = endpoint;u;u = parent[u]) mark[u] = true;
	for(int i = 1;i < cnt;i++)
		if(mark[from[i]] && mark[to[i]])
			weigh[i] = -1;
	calc_dp(1, 0);
	return 2*n-diameter1-diameter2;
}
void get_input()
{
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n-1;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
}
int main()
{
	get_input();
	printf("%d\n", solve());
	return 0;
}
