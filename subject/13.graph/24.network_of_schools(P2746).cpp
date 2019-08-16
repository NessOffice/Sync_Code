#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 5010;
int n, m, color_tot, color[MAXN];
int deg_in[MAXN], deg_out[MAXN], cnt_deg_in_zero, cnt_deg_out_zero;
int depth, top, dfn[MAXN], low[MAXN], sta[MAXN], in_sta[MAXN];
vector<int> G[MAXN];
map<int, bool> G_new_vis[MAXN];
void tarjan(int u)
{
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
		color[u] = ++color_tot;
		while(sta[top] != u)
		{
			color[sta[top]] = color_tot;
			in_sta[sta[top--]] = 0;
		}
		top--;
	}
}
int main()
{
	depth = top = color_tot = 0;
	cnt_deg_in_zero = cnt_deg_out_zero = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(sta, 0, sizeof(sta));
	memset(in_sta, 0, sizeof(in_sta));
	scanf("%d", &n);
	for(int u = 1;u <= n;u++)
	{
		int v;
		while(1)
		{
			scanf("%d", &v);
			if(v == 0) break;
			G[u].push_back(v);
		}
	}
	for(int u = 1;u <= n;u++)
		if(!dfn[u]) tarjan(u);
	for(int u = 1;u <= n;u++)
	{
		for(int i = G[u].size()-1;i >= 0;i--)
		{
			int v = G[u][i];
			int cu = color[u];
			int cv = color[v];
			if(cu != cv && !G_new_vis[cu].count(cv))
			{
				G_new_vis[cu][cv] = true;
				deg_in[cv]++;
				deg_out[cu]++;
			}
		}
	}
	for(int cu = 1;cu <= color_tot;cu++)
	{
		if(deg_in[cu] == 0)
			cnt_deg_in_zero++;
		if(deg_out[cu] == 0)
			cnt_deg_out_zero++;
	}
	if(color_tot == 1) printf("1\n0\n"); // special case!
	else printf("%d\n%d\n", cnt_deg_in_zero, max(cnt_deg_in_zero, cnt_deg_out_zero));
	return 0;
}
