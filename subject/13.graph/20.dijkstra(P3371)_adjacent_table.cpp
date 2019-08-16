#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 10;
const int INF = 2147483647;
int n, m, start;
int dis[MAXN];
bool book[MAXN];
vector<int> G[MAXN];
vector<int> weigh[MAXN];
int search_min()
{
	int minv = INF, u;
	for(int i = 1;i <= n;i++)
	{
		if(!book[i] && dis[i] < minv)
		{
			minv = dis[i];
			u = i;
		}
	}
	return u;
}
void dijkstra()
{
	for(int i = G[start].size()-1;i >= 0;i--)
	{
		int u = G[start][i];
		dis[u] = weigh[start][i];
	}
	for(int i = 1;i < n;i++)
	{
		int u = search_min();
		book[u] = true;
		for(int j = G[u].size()-1;j >= 0;j--)
		{
			int v = G[u][j];
			dis[v] = min(dis[v], dis[u] + weigh[u][j]);
		}
	}
}
void init()
{
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		dis[i] = INF;
	}
	book[start] = true;
	dis[start] = 0;
}
int main()
{
	scanf("%d%d%d", &n, &m, &start);
	init();
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(u == v) continue; // fuck loops!
		bool flag_push = true;
		for(int i = G[u].size()-1;i >= 0;i--)
			if(G[u][i] == v)
			{
				weigh[u][i] = min(weigh[u][i], w);
				flag_push = false;
			}
		if(flag_push)
		{
			G[u].push_back(v);
			weigh[u].push_back(w);
		}
	}
	dijkstra();
	for(int i = 1;i <= n;i++)
		printf("%d ", dis[i]);
	return 0;
}
