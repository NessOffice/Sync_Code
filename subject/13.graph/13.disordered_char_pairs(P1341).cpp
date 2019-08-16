// how foolish to use an adjacent table to represent the graph!
// I should have thought about using an adjacent matrix
#include <cstdio>
#include <cstring>
const int MAXN = 256;
int n, num_ch, vis2[MAXN], vis[MAXN], cnt = 0;
int G[MAXN][MAXN], deg[MAXN];
char ans[MAXN*MAXN];
void dfs(int u)
{
	vis[u] = 1;
	cnt++;
	for(int v = 'A';v <= 'z';v++)
	{
		if(v == u) continue;
		if(vis[v]) continue;
		if(G[u][v]) dfs(v);
	}
}
void euler(int u)
{
	// putchar(u);
	// caution!
	for(int v = 'A';v <= 'z';v++)
	{
		// if(v == u) continue;
		// caution!
		if(G[u][v])
		{
			G[u][v] = G[v][u] = 0;
			euler(v);
		}
	}
	ans[n--] = u;
}
void solve()
{
	for(int u = 'A';u <= 'z';u++)
	{
		if(!deg[u]) continue;
		dfs(u);
		if(cnt < num_ch)
		// < num_ch, not < n
		{
			printf("No Solution\n");
			return;
		}
		break;
	}
	// above: judge the connectivity of the graph

	int head = 0, odd = 0;
	for(int u = 'A';u <= 'z';u++)
	{
		if(deg[u] & 1)
		{
			odd++;
			if(!head) head = u;
		}
	}
	if(odd == 1 || odd > 2)
	{
		printf("No Solution\n");
		return;
	}
	for(int u = 'A';u <= 'z' && !head;u++)
		if(deg[u]) head = u;
	// above: judge the euler path of the graph

	euler(head);
	printf("%s", ans);
}
void init()
{
	cnt = num_ch = 0;
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	memset(G, 0, sizeof(G));
	memset(deg, 0, sizeof(deg));

	// vis counts the connectivity of the characters
	// vis2 counts the number of characters
}
void read()
{
	char pair[3];
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%s", pair);
		int ch1 = int(pair[0]), ch2 = int(pair[1]);
		G[ch1][ch2] = 1;
		G[ch2][ch1] = 1;
		deg[ch1]++;
		deg[ch2]++;
		if(!vis2[ch1])
		{
			num_ch++;
			vis2[ch1] = 1;
		}
		if(!vis2[ch2])
		{
			num_ch++;
			vis2[ch2] = 1;
		}
	}
}
int main()
{
	init();
	read();
	solve();
	return 0;
}
