#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int maxn = 52 + 2;
int G[maxn][maxn], vis[maxn];
bool bound;
void circleDFS(int u)
{
	if(!bound) return;
	vis[u] = -1;
	for(int v = 0;v < maxn;v++) if(G[u][v])
	{
		int dv = v % 2 ? -1 : 1;
		switch(vis[v + dv])
		{
			case -1:bound = false;break;
			case 0:circleDFS(v + dv);break;
		}
	}
	vis[u] = 1;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d", &n) == 1)
	{
		bound = true, memset(G, 0, sizeof(G)), memset(vis, 0, sizeof(vis));
		char box[10];
		for(int i = 0;i < n;i++)
		{
			scanf("%s", box);
			int plus[4];
			for(int j = 0;j < 4;j++)
			{
				plus[j] = - 2 * 'A';
				if(box[2 * j + 1] == '-') plus[j]++;
			}
			for(int j = 0;j < 4;j++)
			for(int k = 0;k < 4;k++)
			{
				if(k == j) continue;
				if(isalpha(box[2*j]) && isalpha(box[2*k]))
					G[2*box[2*j]+plus[j]][2*box[2*k]+plus[k]] = 1;
			}
		}
		for(int i = 0;i < maxn && bound;i++)
			if(!vis[i]) circleDFS(i);
		printf("%s\n", bound ? "bounded" : "unbounded");
	}
	return 0;
}
