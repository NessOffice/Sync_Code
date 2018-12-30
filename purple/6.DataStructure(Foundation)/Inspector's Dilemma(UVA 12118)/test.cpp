#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000 + 5;
int vis[maxn];
vector<int> G[maxn];
int linkDFS(int u)
{
	vis[u] = 1;
	int odd = G[u].size() & 1;
	for(int i = 0, len = G[u].size();i < len;i++)
		if(!vis[G[u][i]]) odd += linkDFS(G[u][i]);
	return odd;
}
int main()
{
	int V, E, T, a, b, kase = 0;
	while(scanf("%d%d%d", &V, &E, &T), V || E || T)
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 0;i < maxn;i++) G[i].clear();
		for(int i = 1;i <= E;i++)
		{
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = 0, odds;
		for(int u = 1;u <= V;u++)
		{
			odds = 0;
			if(!vis[u] && !G[u].empty())
				odds = linkDFS(u), ans++;
			if(odds > 2) ans += ((odds - 2) / 2);
		}
		if(E) ans += (E - 1);
		ans *= T;
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}