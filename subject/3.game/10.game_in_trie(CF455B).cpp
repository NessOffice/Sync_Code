#include <cstdio>
#include <cstring>
const int maxn = 1e6+5;
const int sz_of_dict = 26;
int tree[maxn][sz_of_dict], cnt, n, k;
char word[maxn];
int ch2int(char ch){return ch - 'a';}
int dfs(int node)
{
	int ans = 0;
	bool is_leaf = true;
	for(int ch = 0;ch < sz_of_dict;ch++)
	{
		if(!tree[node][ch]) continue;
		is_leaf = false;
		ans |= dfs(tree[node][ch]);
	}
	ans ^= 3;
	return is_leaf ? 1 : ans;
}
int main()
{
	scanf("%d%d", &n, &k);
	while(n--)
	{
		scanf("%s", word);
		int node = 0;
		for(int i = 0, len = strlen(word);i < len;i++)
		{
			char ch = word[i];
			if(!tree[node][ch2int(ch)])
				tree[node][ch2int(ch)] = ++cnt;
			node = tree[node][ch2int(ch)];
		}
	}
	int ans = dfs(0);
	printf("%s\n", (!ans || (ans == 2 && (k & 1))) ? "First" : "Second");
	return 0;
}
