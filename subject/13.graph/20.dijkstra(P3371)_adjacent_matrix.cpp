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
int weigh[MAXN][MAXN];
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
	for(int u = 1;u <= n;u++)
		dis[u] = weigh[start][u];
	for(int i = 1;i < n;i++)
	{
		int u = search_min();
		book[u] = true;
		for(int v = 1;v <= n;v++)
			if(weigh[u][v] != INF)
				dis[v] = min(dis[v], dis[u] + weigh[u][v]);
	}
}
void init()
{
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		for(int j = 1;j <= n;j++)
			weigh[i][j] = INF;
		weigh[i][i] = 0;
	}
	book[start] = true;
}
int main()
{
	scanf("%d%d%d", &n, &m, &start);
	init();
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		weigh[u][v] = min(weigh[u][v], w); // fuck: multiedges!
	}
	dijkstra();
	for(int i = 1;i <= n;i++)
		printf("%d ", dis[i]);
	return 0;
}

/*
input:
5 15 5
2 2 270
1 4 89
2 1 3
5 5 261
5 2 163
5 5 275
4 5 108
4 4 231
3 4 213
3 3 119
3 1 77
3 1 6
2 4 83
5 5 196
5 5 94

output:
166 163 2147483647 246 0 
*/