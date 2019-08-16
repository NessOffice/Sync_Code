#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int G[22][22], vis[22], len[22], ans = 0;
vector<int> neighbor[22];
void dfs(int u, int l)
{
	for(int j = neighbor[u].size()-1;j >= 0;j--)
	{
		int v = neighbor[u][j];
		if(vis[v] < 2)
		{
			vis[v]++;
			dfs(v, l + len[v] - G[u][v]);
			vis[v]--;
		}
	}
	if(l > ans) ans = l;
}
int main()
{
	int n;
	scanf("%d", &n);
	char words[22][22];
	for(int i = 0;i < n;i++)
	{
		neighbor[i].clear();
		scanf("%s", words[i]);
		len[i] = strlen(words[i]);
	}
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
	for(int k = 1, k2;k < len[i] && k < len[j];k++)
	{
		for(k2 = 0;k2 < k;k2++)
			if(words[i][len[i]-k+k2] != words[j][k2])
				break;
		if(k2 == k)
		{
			G[i][j] = k;
			neighbor[i].push_back(j);
			break;
		}
	}
	char ch[2];
	scanf("%s", ch);
	for(int i = 0;i < n;i++)
		if(words[i][0] == ch[0])
		{
			memset(vis, 0, sizeof(vis));
			vis[i]++;
			dfs(i, len[i]);
		}
	printf("%d", ans);
	return 0;
}