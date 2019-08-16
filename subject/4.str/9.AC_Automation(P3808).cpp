#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
struct AC_Automation{
	int son[maxn][26], val[maxn], fail[maxn], cnt;
	void insert(char* word) // build trie
	{
		int pos = 0;
		for(int i = 0, len = strlen(word);i < len;i++)
		{
			int ch = word[i] - 'a';
			if(son[pos][ch] == 0)
				son[pos][ch] = ++cnt;
			pos = son[pos][ch];
		}
		val[pos]++;
	}
	void build() // calc "fail" arrays
	{
		queue<int> q;
		for(int ch = 0;ch < 26;ch++)
			if(son[0][ch])
			{
				fail[son[0][ch]] = 0;
				q.push(son[0][ch]);
			}
		while(!q.empty())
		{
			int pos = q.front();q.pop();
			for(int ch = 0;ch < 26;ch++)
				if(son[pos][ch]){
					fail[son[pos][ch]] = son[fail[pos]][ch];
					q.push(son[pos][ch]);
				}else
					son[pos][ch] = son[fail[pos]][ch];
		}
	}
	int query(char* target_str)
	{
		int ans = 0, pos = 0;
		for(int i = 0, len = strlen(target_str);i < len;i++)
		{
			int ch = target_str[i] - 'a';
			pos = son[pos][ch];
			for(int ptr = pos;ptr && ~val[ptr];ptr = fail[ptr])
				ans += val[ptr],
				val[ptr] = -1;
		}
		return ans;
	}
}AC;
int main()
{
	AC.cnt = 0;
    int n;
	char pattern[maxn];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", pattern);
		AC.insert(pattern);
	}
	AC.build();
	char* text = pattern;
	scanf("%s", text);
	printf("%d", AC.query(text));
    return 0;
}
