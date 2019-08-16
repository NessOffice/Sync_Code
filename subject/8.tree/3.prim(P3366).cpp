#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 5e3 + 10;
const int MAXM = 2e5 + 10;
const int INF = 2147483647;
int num_of_vertice, weigh;
int n, m, start;
int dis[MAXN];
bool book[MAXN];
// in the PRIM algorithm, the array "dis" is a bit different from that in the DIJKSTRA algorithm
struct Node{
	int u, w;
	bool operator < (const Node& rhs) const{return w > rhs.w;} // top: w is the smallest
};
struct Edge{
	int to;
	int w;
	int next;
}G[MAXM << 1];
int cnt, head[MAXN];
void add_edge(int u, int v, int w)
{
	cnt++;
	G[cnt].to = v;
	G[cnt].w = w;
	G[cnt].next = head[u];
	head[u] = cnt;
}
void prim()
{
	priority_queue<Node> q;
	q.push((Node){start, 0});
	while(!q.empty())
	{
		Node temp = q.top();q.pop();
		int u = temp.u;
		if(book[u]) continue;
		book[u] = true;
		weigh += temp.w;
		num_of_vertice++;
		for(int i = head[u];i;i = G[i].next)
		{
			int v = G[i].to;
			if(!book[v] && dis[v] > G[i].w)
			{
				dis[v] = G[i].w;
				q.push((Node){v, dis[v]});
			}
		}
		if(num_of_vertice == n)
			return;
	}
}
void init()
{
	start = 1;
	cnt = num_of_vertice = weigh = 0;
	memset(head, 0, sizeof(head));
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		dis[i] = INF;
	}
	dis[start] = 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	init();
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	prim();
	if(num_of_vertice == n) printf("%d\n", weigh);
	else printf("orz\n");
	return 0;
}
