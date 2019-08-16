#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 55;
const int maxs = maxn*26;
int son[maxs][26], place[maxs];
char word[maxn];
int cnt1, cnt2, cnt_of_edges;
int head[maxs], nxt[maxs], to[maxs];
void add_edge(int u, int v)
{
	to[++cnt_of_edges] = v;
	nxt[cnt_of_edges] = head[u];
	head[u] = cnt_of_edges;
}
void insert() // build Trie
{
	int pos = 0;
	for(int i = 0, len = strlen(word);i < len;i++)
	{
		int ch = word[i] - 'a';
		if(son[pos][ch] == 0) son[pos][ch] = ++cnt1;
		pos = son[pos][ch];
	}
	place[pos] = pos;
}
void dfs_build(int pos, int root) // get tree from Trie
{
	if(place[pos]){add_edge(root, ++cnt2); root = cnt2;}
	for(int ch = 0;ch < 26;ch++)
		if(son[pos][ch]) dfs_build(son[pos][ch], root);
}
LL dfs_dp(int u)
{
	LL ans = 1LL;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		ans *= dfs_dp(v);
	}
	return ++ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s", word);
		insert();
	}
	dfs_build(0, 0);
	printf("%lld", dfs_dp(0)-1);
	return 0;
}
