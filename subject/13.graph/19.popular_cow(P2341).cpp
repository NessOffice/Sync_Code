#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e4 + 10;
int n, m, color_temp, color[MAXN], vis[MAXN], color_cnt[MAXN];
int depth, top, dfn[MAXN], low[MAXN], sta[MAXN], in_sta[MAXN];
vector<int> G[MAXN];
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
		top--;
	}
}
int main()
{
	depth = top = color_temp = 0;
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
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int u = 1;u <= n;u++)
		if(!vis[u]) tarjan(u);
	
	int deg_out[MAXN], terminal = 0, ans = 0;
	memset(deg_out, 0, sizeof(deg_out));
	// terminal for the "points" whose deg_out == 0
	for(int u = 1;u <= n;u++)
	{
		for(int i = G[u].size()-1;i >= 0;i--)
		{
			int v = G[u][i];
			if(color[u] != color[v])
				deg_out[color[u]]++;
		}
	}
	for(int i = 1;i <= color_temp;i++)
	{
		if(deg_out[i] == 0)
			terminal++,
			ans = max(ans, color_cnt[i]);
	}
	printf("%d\n", (terminal > 1) ? 0 : ans);
	return 0;
}
