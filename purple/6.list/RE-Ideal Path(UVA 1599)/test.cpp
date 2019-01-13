#include <cstdio>
#include <cstring>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
const int maxc = 0x7fffffff;
int n, m, d[maxn], ans[maxn], vis[maxn];
vector<int> G[maxn];
vector<int> color[maxn];
void pathBFS()
{
	queue<int> nodes;
	nodes.push(n);
	d[n] = 0;
	while(1)
	{
		int u = nodes.front();nodes.pop();
		int len = G[u].size(), v;
		for(int i = 0;i < len;i++)
		{
			v = G[u][i];
			if(d[v] == -1)
			{
				d[v] = d[u] + 1;
				if(v != 1) nodes.push(v);
				else break;
			}
		}
		if(v == 1) break;
	}
	queue<int> out;
	out.push(1);
	while(1)
	{
		int u = out.front();out.pop();
		if(u == n) break;
		int color_min = maxc, len = G[u].size(), v;
		for(int i = 0;i < len;i++)
		{
			v = G[u][i];
			if(d[v] == d[u] - 1)
				color_min = min(color_min, color[u][i]);
		}
		int index = d[1] - d[u];
		if(ans[index] == -1) ans[index] = color_min;
		else ans[index] = min(color_min, ans[index]);
		for(int i = 0;i < len;i++)
		{
			v = G[u][i];
			if(!vis[v] && d[v] == d[u] - 1 && color[u][i] == color_min)
			{
				out.push(v);
				vis[v] = 1;
			}
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int a, b, c;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(int i = 0;i <= n;i++)
		{
			G[i].clear();
			color[i].clear();
		}
		memset(d, -1, sizeof(d));
		memset(ans, -1, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		while(m--)
		{
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(b);
			G[b].push_back(a);
			color[a].push_back(c);
			color[b].push_back(c);
		}
		pathBFS();
		printf("%d\n%d", d[1], ans[0]);
		for(int i = 1;i < d[1];i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
