#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 2e2 + 5;
int n, m, t[MAXN], q;
int dis[MAXN][MAXN];
void floyd(int mid)
{
	for(int u = 0;u < n;u++)
	for(int v = 0;v < n;v++)
		if(dis[u][mid] != -1 && dis[v][mid] != -1)
		if(dis[u][v] == -1 || dis[u][mid] + dis[v][mid] < dis[u][v])
			dis[u][v] = dis[v][u] = dis[u][mid] + dis[v][mid]; // caution! undirected
}
int main()
{
	for(int i = 0;i < MAXN;i++)
	{
		for(int j = 0;j < MAXN;j++)
			dis[i][j] = -1;
		dis[i][i] = 0;
	}
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%d", &t[i]);
	for(int i = 0;i < m;i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = dis[v][u] = w;
	}
	int last = 0; // last for the last village rebuilt
	scanf("%d", &q);
	while(q--)
	{
		int u, v, t_temp;
		scanf("%d%d%d", &u, &v, &t_temp);
		while(last < n && t[last] <= t_temp)
		{
			floyd(last);
			last++;
		}
		if(t[u] > t_temp || t[v] > t_temp) printf("-1\n");
		else printf("%d\n", dis[u][v]);
	}
	return 0;
}
