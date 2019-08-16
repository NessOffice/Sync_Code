#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 2e5 + 7;
int n, vis[maxn], map[maxn], in[maxn], ans = maxn;
void dfs(int begin, int u, int l)
{
	if(begin == u && l)
		ans = std::min(ans, l);
	else
	{
		vis[map[u]] = 1;
		dfs(begin, map[u], l+1);
	}
}
void remove(int i)
{
	vis[i] = -1;
	in[map[i]]--;
	if(vis[map[i]] != -1 && !in[map[i]])
		remove(map[i]);
}
int main()
{
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &map[i]);
		in[map[i]]++;
	}
	for(int i = 1;i <= n;i++)
		if(vis[i] != -1 && !in[i])
			remove(i);
	for(int i = 1;i <= n;i++)
		if(!vis[i]) dfs(i, i, 0);
	printf("%d", ans);
	return 0;
}