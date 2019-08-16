#include <cstdio>
#include <cstring>
const int MAXN = 1005;
int n, m, e;
int G[MAXN][MAXN];
int vis[MAXN], matched[MAXN];
bool find(int lft) // lft for the one in the LHS, while rgt for the one in the RHS
{
	for(int rgt = 1;rgt <= m;rgt++)
	{
		if(!G[lft][rgt]) continue;
		if(vis[rgt]) continue;
		vis[rgt] = 1;
		if(!matched[rgt] || find(matched[rgt]))
		{
			matched[rgt] = lft;
			return true;
		}
	}
	return false;
}
int main()
{
	int ans = 0;
	scanf("%d%d%d", &n, &m, &e);
	while(e--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = 1;
	}
	for(int lft = 1;lft <= n;lft++)
	{
		memset(vis, 0, sizeof(vis));
		if(find(lft)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

/*
4 4 7
1 1
1 2
2 2
2 3
3 1
3 2
4 3
*/