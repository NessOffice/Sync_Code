#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2e4 + 5;
int n, m, cut[MAXN];
int depth, dfn[MAXN], low[MAXN], parent[MAXN];
vector<int> G[MAXN];
void link_vertice(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void tarjan(int u)
{
	dfn[u] = ++depth;
	low[u] =   depth;
	int child = 0;
	for(int i = G[u].size()-1;i >= 0;i--)
	{
		int v = G[u][i];
		if(!dfn[v]) // only if the node has at least a descendant, it can be a cut vertex
		{
			child++;
			parent[v] = u;
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if(!parent[u] && child >= 2) cut[u] = 1;
			if(parent[u] && low[v] >= dfn[u]) cut[u] = 1;
		}
		else if(v != parent[u])
			low[u] = min(low[u], dfn[v]); // I dont understand
	}
}
void init()
{
	depth = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(cut, 0, sizeof(cut));
	memset(parent, 0, sizeof(parent));
}
void output()
{
	int tot = 0;
	for(int u = 1;u <= n;u++)
		if(cut[u]) tot++;
	printf("%d\n", tot);
	for(int u = 1;u <= n;u++)
		if(cut[u]) printf("%d ", u);
}
int main()
{
	init();
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link_vertice(u, v);
	}
	for(int u = 1;u <= n;u++)
		if(!dfn[u]) tarjan(u);
	output();
	return 0;
}

/*
4 4
1 2
2 3
1 3
3 4
*/