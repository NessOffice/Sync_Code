#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n, q, root;
bool vis[maxn];
int pre[maxn];
int ans[maxn];
int head_edge[maxn], head_query[maxn];
struct Node{int to, next, index;}edges[maxn], queries[maxn];
void add_edge(int u, int v, int cnt)
{
	edges[cnt].to = v;
	edges[cnt].next = head_edge[u];
	head_edge[u] = cnt;
}
void add_query(int u, int v, int cnt, int index)
{
	queries[cnt].to = v;
	queries[cnt].next = head_query[u];
	queries[cnt].index = index;
	head_query[u] = cnt;
}
int find(int u)
{
	int fu = pre[u];
	while(fu != pre[fu])
		fu = pre[fu];
	return pre[u] = fu;
}
void merge(int u, int v)
{
	pre[u] = find(v);
}
void tarjan(int u)
{
	vis[u] = true;
	for(int i = head_edge[u];i != -1;i = edges[i].next)
	{
		int v = edges[i].to;
		if(!vis[v])
		{
			tarjan(v);
			merge(v, u);
		}
	}
	for(int i = head_query[u];i != -1;i = queries[i].next)
	{
		int v = queries[i].to;
		if(!vis[v]) continue;
		ans[queries[i].index] = find(v);
	}
}
int main()
{
	memset(head_edge, -1, sizeof(head_edge));
	memset(head_query, -1, sizeof(head_query));
	scanf("%d%d%d", &n, &q, &root);
	for(int u = 1;u <= n;u++)
	{
		vis[u] = false;
		pre[u] = u;
	}
	for(int i = 0;i < n-1;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v, 2*i);
		add_edge(v, u, 2*i+1);
	}
	for(int i = 0;i < q;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_query(u, v, 2*i, i);
		add_query(v, u, 2*i+1, i);
	}
	tarjan(root);
	for(int i = 0;i < q;i++)
		printf("%d\n", ans[i]);
	return 0;
}

/*
9 28 1
1 2
2 4
2 5
5 7
7 9
5 8
1 3
3 6

1 2
1 3
1 4
1 5
1 6
1 7
1 8
2 3
2 4
2 5
2 6
2 7
2 8
3 4
3 5
3 6
3 7
3 8
4 5
4 6
4 7
4 8
5 6
5 7
5 8
6 7
6 8
7 8
*/