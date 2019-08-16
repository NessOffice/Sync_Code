// the idea is to build a maximum spanning tree from the given graph
// it seems that there will be exactly one tree
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 5e4 + 10;
const int INF = 1e8;
int n, m;
int pre[MAXN];
struct Edge_origin{int u, v, w}G_origin[MAXM];
struct Edge{int to, next, w;}G[MAXM];
int head[MAXN];
int cnt, root, depth[MAXN];
int hop[MAXN][18]; // 2**15 = 32768
bool cmp(const Edge_origin& lhs, const Edge_origin& rhs)
{
	return lhs.w > rhs.w;
}
void add_edge(int u, int v, int w)
{
	G[cnt].to = v;
	G[cnt].next = head[u];
	G[cnt].w = w;
	head[u] = cnt;
	cnt++;
}
void init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(depth, -1, sizeof(depth));
	for(int i = 1;i <= n;i++)
		pre[i] = i;
	for(int i = 0;i < MAXN;i++)
	for(int j = 0;j < 18;j++)
		hop[i][j] = INF;
}
int find(int u)
{
	int fu = pre[u];
	while(fu != pre[fu])
		fu = pre[fu];
	return pre[u] = fu;
}
void krustral()
{
	sort(G, G+m, cmp);
	for(int i = 0;i < m;i++)
	{
		int fu = find(G_origin[i].u),
		    fv = find(G_origin[i].v);
		if(fu != fv)
		{
			pre[fv] = fu;
			add_edge(fu, fv, G_origin[i].w);
			add_edge(fv, fu, G_origin[i].w);
		}
	}
}
void find_root()
{
	for(int u = 1;u <= n;u++)
		if(head[u] != -1)
		{
			root = u;
			return;
		}
}
void dfs(int u, int d)
{
	depth[u] = d;
	for(int i = head[u];i != -1;i = G[i].next)
	{
		int v = G[i].to;
		if(depth[v] != -1)
		{
			hop[v][0] = u;
			dfs(v, d+1);
		}
	}
}
void doubling_algorithm()
{
	for(int i = 1;i < 18;i++)
	{
		for(int u = 1;u <= n;u++)
		{
			if(depth[u] <= 0) continue;
			hop[u][i] = hop[hop[u][i-1]][i-1];
		}
	}
}
int query(int node1, int node2)
{
	int ans = 0;
	if(depth[node1] < depth[node2]) // node1 is always deeper than node2
		return query(node2, node1);
	while(depth[node1] > depth[node2])
	{
		for(int i = 0;i < 18;i++)
		{
			int hop_1 = hop[node1][i], hop_2 = hop[node1][i+1];
			if(depth[hop_1] <= depth[node2] && depth[node2] < depth[hop_2])
			{
				node1 = hop_1;
				ans += (1 << i);
				break;
			}
		}
	} // now depth[node1] == depth[node2]
	while(node1 != node2)
	{
		for(int i = 0;i < 18;i++)
		{
			
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	init();
	for(int i = 0;i < m;i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G_origin[i].u = u;
		G_origin[i].v = v;
		G_origin[i].w = w;
	}
	krustral();
	find_root();
	dfs(root, 0);
	doubling_algorithm();
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(depth[u] == -1 || depth[v] == -1)
			printf("-1\n");
		else
			printf("%d\n", query(u, v));
	}
	return 0;
}
