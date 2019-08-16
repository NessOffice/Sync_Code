#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxlen = 2e5+5;
char pattern[maxlen], text[int(2e6+5)];
int n, matches[maxlen], index2pos[maxlen];
struct AC_Automation{
	int son[maxlen][26], fail[maxlen], cnt_of_pos;
	int head[maxlen], nxt[maxlen], to[maxlen], cnt_of_edge;
	void init()
	{
		cnt_of_pos = 0;
		cnt_of_edge = 0;
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(to, 0, sizeof(to));
		memset(son, 0, sizeof(son));
		memset(index2pos, 0, sizeof(index2pos));
		memset(fail, 0, sizeof(fail));
		memset(matches, 0, sizeof(matches));
	}
	void add_edge(int u, int v) // build the "fail" tree
	{
		to[++cnt_of_edge] = v;
		nxt[cnt_of_edge] = head[u];
		head[u] = cnt_of_edge;
	}
	void dfs(int u)
	{
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			dfs(v);
			matches[u] += matches[v];
		}
	}
	void insert(char* word, int index) // build trie
	{
		int pos = 0;
		for(int i = 0, len = strlen(word);i < len;i++)
		{
			int ch = word[i] - 'a';
			if(son[pos][ch] == 0)
				son[pos][ch] = ++cnt_of_pos;
			pos = son[pos][ch];
		}
		index2pos[index] = pos;
	}
	void build() // calc "fail" arrays
	{
		queue<int> q;
		for(int ch = 0;ch < 26;ch++)
			if(son[0][ch])
			{
				fail[son[0][ch]] = 0;
				add_edge(0, son[0][ch]);
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
					add_edge(fail[v], v);
					q.push(v);
				}else
					v = son[fail[pos]][ch];
			}
		}
	}
	void query(char* target_str)
	{
		int pos = 0;
		for(int i = 0, len = strlen(target_str);i < len;i++)
		{
			int ch = target_str[i] - 'a';
			pos = son[pos][ch];
			matches[pos]++;
		}
		dfs(0);
	}
}AC;
int main()
{
	scanf("%d", &n);
	AC.init();
	for(int i = 1;i <= n;i++)
	{
		scanf("%s", pattern);
		AC.insert(pattern, i);
	}
	AC.build();
	scanf("%s", text);
	AC.query(text);
	for(int i = 1;i <= n;i++)
		printf("%d\n", matches[index2pos[i]]);
	return 0;
}
