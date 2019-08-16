#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, color_temp, color[MAXN];
int depth, top, dfn[MAXN], low[MAXN], sta[MAXN], in_sta[MAXN];
int weigh[MAXN], weigh_new[MAXN];
vector<int> G[MAXN];
vector<int> G_new[MAXN];
// sta stands for stack, and in_sta indicates if the element is in sta
int f[MAXN];
// int dp(int u_new)
// {
// 	if(f[u_new]) return f[u_new];
// 	f[u_new] = 0;
// 	for(int i = G_new[u_new].size()-1;i >= 0;i--)
// 	{
// 		int v_new = G_new[u_new][i];
// 		f[u_new] = max(f[u_new], dp(v_new) + weigh_new[v_new]);
// 	}
// 	f[u_new] += weigh_new[u_new];
// 	return f[u_new];
// }
void search(int u_new)
{
	if(f[u_new]) return;
	f[u_new] = weigh_new[u_new];
	int ans = 0;
	for(int i = G_new[u_new].size()-1;i >= 0;i--)
	{
		int v_new = G[u_new][i];
		if(!f[v_new]) search(v_new);
		ans = max(ans, f[v_new] + weigh_new[v_new]);
	}
	f[u_new] += ans;
}
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
		color[u] = ++color_temp;
		weigh_new[color_temp] = weigh[u];
		while(sta[top] != u)
		{
			color[sta[top]] = color_temp;
			weigh_new[color_temp] += weigh[top];
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
	memset(weigh, 0, sizeof(weigh));
	memset(weigh_new, 0, sizeof(weigh_new));
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d", &weigh[i]);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int u = 1;u <= n;u++)
		if(!dfn[u]) tarjan(u);
	for(int u = 1;u <= n;u++)
	{
		for(int i = G[u].size()-1;i >= 0;i--)
		{
			int v = G[u][i];
			if(color[u] != color[v])
				G_new[color[u]].push_back(color[v]);
		}
	}
	int ans = 0;
	for(int u_new = 1;u_new <= color_temp;u_new++)
		if(!f[u_new])
		{
			// ans = max(ans, dp(u_new));
			search(u_new);
			ans = max(ans, weigh_new[u_new]);
		}
	printf("%d\n", ans);
	return 0;
}
