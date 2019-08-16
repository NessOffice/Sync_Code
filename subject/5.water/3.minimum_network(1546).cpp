#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 10;
int n, m, weigh;
int pre[MAXN];
struct Edge{int from, to, w;}G[MAXM];
int cnt, num_of_edge;
bool cmp(const Edge& lhs, const Edge& rhs)
{
	return lhs.w < rhs.w;
}
void add_edge(int u, int v, int w)
{
	G[cnt].to = v;
	G[cnt].from = u;
	G[cnt].w = w;
	cnt++;
}
void init()
{
	cnt = num_of_edge = weigh = 0;
	for(int i = 1;i <= n;i++)
		pre[i] = i;
}
int find(int u)
{
	int fu = pre[u];
	while(fu != pre[fu])
		fu = pre[fu];
	return pre[u] = fu;
}
void krustral()
{
	sort(G, G+cnt, cmp);
	for(int i = 0;i < cnt;i++)
	{
		int fu = find(G[i].from),
		    fv = find(G[i].to);
		if(fu != fv)
		{
			weigh += G[i].w;
			pre[fv] = fu;
			num_of_edge++;
		}
		if(num_of_edge == n-1)
			return;
	}
}
int main()
{
	scanf("%d", &n);
	init();
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			int w;
			scanf("%d", &w);
			if(j <= i) continue;
			add_edge(i, j, w);
		}
	}
	krustral();
	printf("%d\n", weigh);
	return 0;
}
