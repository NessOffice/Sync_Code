#include <cstdio>
#include <cstring>
const int MAXN = 200005;
int n, map[MAXN], vis[MAXN], d[MAXN], ans = MAXN;
int main()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &map[i]);
	for(int i = 1;i <= n;i++)
	{
		int node = i, node_next = map[i];
		d[node] = 0;
		while(vis[node_next] != i)
		{
			if(vis[node_next] && vis[node_next] < i) break; // avoid visiting the circuits visited
			vis[node] = i;
			d[node_next] = d[node] + 1;
			node = node_next;
			node_next = map[node];
		}
		if(vis[node_next] == i)
			if(ans > d[node] - d[node_next] + 1)
				ans = d[node] - d[node_next] + 1;
	}
	printf("%d", ans);
	return 0;
}