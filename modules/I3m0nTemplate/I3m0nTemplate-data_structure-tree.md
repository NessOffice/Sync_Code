# 1.树的直径

~~~cpp
// two ways to calculate the diameter of a tree
// dfs can find the vertice in the diameter
// dp can deal with edges with negative weighs
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
void solve()
{
    // dfs
	dfs(1, 0, 0);
	int root = find_endpoint();
	dfs(root, 0, 0);
	int endpoint = find_endpoint();
	int diameter1 = depth[endpoint];

	// dp
	calc_dp(1, 0);
}
~~~

# 2.树的重心

