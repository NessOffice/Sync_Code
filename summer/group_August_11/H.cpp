#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 405;
bitset<maxn> connectivity[maxn];
int a_pow[maxn] = {1}, b_pow[maxn] = {1}, n, q, a, b;;
bool g[maxn][maxn], vis[maxn];
void dfs(int u)
{
	vis[u] = true;
	for(int v = 1;v <= n;v++)
		if(v != u && g[u][v])
		{
			if(vis[v] == false) dfs(v);
			connectivity[u].set(v);
			connectivity[u] |= connectivity[v];
		}
}
void print_ans()
{
	memset(vis, 0, sizeof(vis));
	for(int i = 1;i <= n;i++)
		connectivity[i].reset();
	for(int i = 1;i <= n;i++)
		if(vis[i] == false) dfs(i);
	unsigned int ans = 0;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++)
	{
		if(i == j) continue;
		if(connectivity[i][j] == 0) continue;
		ans += a_pow[i-1]*b_pow[j-1];
	}
	printf("%u\n", ans);
}
int main()
{
	freopen("reachability.in","r",stdin);
	freopen("reachability.out","w",stdout);
	scanf("%d%d%d%d", &n, &q, &a, &b);
	for(int i = 1;i <= n;i++)
		a_pow[i] = a_pow[i-1] * a,
		b_pow[i] = b_pow[i-1] * b;
	while(q--)
	{
		char cmd[2][2];
		int x, y, k;
		scanf("%s%s%d%d", cmd[0], cmd[1], &x, &k);
		while(k--)
		{
			scanf("%d", &y);
			if(cmd[1][0] == 'o')
				g[x][y] ^= 1;
			else
				g[y][x] ^= 1;
		}
		print_ans();
	}
	return 0;
}
/*
2 4 3 7 + o 1 1 2 - i 2 1 1 + i 1 1 2 - o 2 1 1
*/