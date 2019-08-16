#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 155;
const int maxlen = 75;
const int maxsize = maxn*maxlen; // caution
char patterns[maxn][maxlen], text[int(1e6+5)];
int n, matches[maxn];
struct AC_Automation{
	int son[maxsize][26], val[maxsize], fail[maxsize], last[maxsize], cnt;
	void init()
	{
		cnt = 0;
		memset(son, 0, sizeof(son));
		memset(val, 0, sizeof(val));
		memset(fail, 0, sizeof(fail));
		memset(last, 0, sizeof(last));
		memset(matches, 0, sizeof(matches));
	}
	void insert(char* word, int index) // build trie
	{
		int pos = 0;
		for(int i = 0, len = strlen(word);i < len;i++)
		{
			int ch = word[i] - 'a';
			if(son[pos][ch] == 0)
				son[pos][ch] = ++cnt;
			pos = son[pos][ch];
		}
		val[pos] = index;
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
			{
				int& v = son[pos][ch];
				if(v){
					fail[v] = son[fail[pos]][ch];
					last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
					q.push(v);
				}else
					v = son[fail[pos]][ch];
			}
		}
	}
	int query(char* target_str)
	{
		int ans = 0, pos = 0;
		for(int i = 0, len = strlen(target_str);i < len;i++)
		{
			int ch = target_str[i] - 'a';
			pos = son[pos][ch];
			for(int ptr = pos;ptr;ptr = last[ptr])
				if(val[ptr])
				{
					matches[val[ptr]]++;
					ans = max(ans, matches[val[ptr]]);
				}
		}
		return ans;
	}
}AC;
int main()
{
	//  freopen("in.txt", "r", stdin);
	//  freopen("out2.txt", "w", stdout);
	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		AC.init();
		for(int i = 1;i <= n;i++)
		{
			scanf("%s", patterns[i]);
			AC.insert(patterns[i], i);
		}
		AC.build();
		scanf("%s", text);
		int cnt_of_match = AC.query(text);
		printf("%d\n", cnt_of_match);
		for(int i = 1;i <= n;i++)
			if(matches[i] == cnt_of_match)
				printf("%s\n", patterns[i]);
	}
	return 0;
}
