#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 5010;
int n, m, color_temp, color[MAXN], vis[MAXN], color_cnt[MAXN], color_max, head;
int depth, top, dfn[MAXN], low[MAXN], sta[MAXN], in_sta[MAXN];
vector<int> G[MAXN];
// head is to give the lexicographic order
// sta stands for stack, and in_sta indicates if the element is in sta
void tarjan(int u)
{
	vis[u] = 1;

	dfn[u] = ++depth;
	low[u] = depth;
	in_sta[u] = 1;
	sta[++top] = u;
	for(int i = G[u].size()-1;i >= 0;i--)
	{
		int v = G[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(in_sta[v])
		{
			low[u] = min(low[u], low[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		in_sta[u] = 0;
		color[u] = ++color_temp;
		color_cnt[color_temp]++;
		while(sta[top] != u)
		{
			color[sta[top]] = color_temp;
			color_cnt[color_temp]++;
			in_sta[sta[top--]] = 0;
		}
		if(color_cnt[color_temp] > color_cnt[color_max]
		||(color_cnt[color_temp] == color_cnt[color_max] && u <= head))
		{
			color_max = color_temp;
			head = u;
		}
		top--;
	}
}
int main()
{
	depth = top = color_temp = 0, head = MAXN;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(sta, 0, sizeof(sta));
	memset(in_sta, 0, sizeof(in_sta));
	memset(vis, 0, sizeof(vis));
	memset(color_cnt, 0, sizeof(color_cnt));
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v, dir;
		scanf("%d%d%d", &u, &v, &dir);
		if(dir >= 1) G[u].push_back(v);
		if(dir >= 2) G[v].push_back(u);
	}
	for(int i = 1;i <= n;i++)
		if(!vis[i]) tarjan(i);
	printf("%d\n", color_cnt[color_max]);
	for(int i = 1;i <= n;i++)
		if(color[i] == color_max)
			printf("%d ", i);
	return 0;
}

/*
6 8
1 2 1
2 3 1
3 6 1
2 5 1
5 6 1
4 5 1
1 4 1
5 1 1
*/