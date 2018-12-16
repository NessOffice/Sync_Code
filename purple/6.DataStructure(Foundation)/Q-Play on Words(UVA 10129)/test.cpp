#include <cstdio>
#include <cstring>
const int maxn = 26 + 2;
int G[maxn][maxn], in[maxn], out[maxn], vis[maxn];
void eulerDFS(int u)
{
	vis[u] = 1;
	for(int v = 0;v < maxn;v++)
		if(G[u][v] && !vis[v])
			eulerDFS(v);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(G, 0, sizeof(G)), memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in)), memset(out, 0, sizeof(out));
	int n, m;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &n);
		memset(G, 0, sizeof(G)), memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in)), memset(out, 0, sizeof(out));
		for(int i = 0;i < n;i++)
		{
			char s[1000 + 5];scanf("%s", s);
			int head = s[0] - 'a', tail = s[strlen(s) - 1] - 'a';
			G[head][tail] = 1, in[head]++, out[tail]++;//I don't understand the case when G[u][v] is larger than 1
		}
		int start = -1, end = -1;
		bool ok = true;
		for(int i = 0;i < maxn && ok;i++)
			if(in[i] != out[i])
			{
				if(in[i] == out[i] + 1 && start == -1) start = i;
				else if(in[i] == out[i] - 1 && end == -1) end = i;
				else ok = false;
			}
		if(ok)
		{
			if(start == -1)
			for(int i = 0;i < maxn;i++)
				if(in[i]){start = i;break;}
			eulerDFS(start);
			for(int i = 0;i < maxn && ok;i++)
				if((in[i] + out[i]) && !vis[i]) ok = false;
		}
		printf("%s", ok? "Ordering is possible.\n":"The door cannot be opened.\n");
	}
	return 0;
}
