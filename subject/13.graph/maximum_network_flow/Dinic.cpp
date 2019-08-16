#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = (1e5+5)*2;
const int INF = 1e9;
struct Node{int to, val, nxt;}edges[maxn];
int n, m, st, ed, cnt;
int head[maxn];
int depth[maxn];
int cur[maxn]; // faster
void add_edge(int index, int u, int v, int val)
{
	edges[index].to = v;
	edges[index].val = val;
	edges[index].nxt = head[u];
	head[u] = index;
}
bool bfs_divide_level()
{
	queue<int> q;
	memset(depth, 0, sizeof(depth));
	depth[st] = 1;
	q.push(st);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = head[u];i != -1;i = edges[i].nxt)
		{
			int v = edges[i].to;
			if(depth[v]) continue;
			if(edges[i].val == 0) continue;
			depth[v] = depth[u] + 1;
			q.push(v);
		}
	}
	return depth[ed] > 0;
}
int dfs_find_argumenting_path(int u, int current_flow)
{
	if(u == ed) return current_flow;
	for(int& i = cur[u];i != -1;i = edges[i].nxt)
	{
		int v = edges[i].to;
		if(depth[v] != depth[u] + 1) continue;
		if(edges[i].val == 0) continue;
		int new_flow = dfs_find_argumenting_path(v, min(current_flow, edges[i].val));
		if(new_flow)
		{
			edges[i].val -= new_flow;
			edges[i^1].val += new_flow;
			return new_flow;
		}
	}
	return 0;
}
int dinic()
{
	int max_flow = 0, delta_flow;
	while(bfs_divide_level())
	{
		for(int i = 1;i <= n;i++) cur[i] = head[i];
		while(delta_flow = dfs_find_argumenting_path(st, INF))
			max_flow += delta_flow;
	}
	return max_flow;
}
int main()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0;i < m;i++)
	{
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		add_edge(2*i, u, v, val);
		add_edge(2*i+1, v, u, 0);
	}
	printf("%d", dinic());
	return 0;
}
