#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
const int INF = 2147483647;
int n, m, start;
int dis[MAXN];
bool book[MAXN];
struct Node{
	int u, d;
	bool operator < (const Node& rhs) const{return d > rhs.d;} // top: d is the smallest
};
struct Edge{
	int to;
	int d;
	int next;
}G[MAXM];
int cnt, head[MAXN];
void add_edge(int u, int v, int w)
{
	cnt++;
	G[cnt].to = v;
	G[cnt].d = w;
	G[cnt].next = head[u];
	head[u] = cnt;
}
void dijkstra()
{
	priority_queue<Node> q;
	q.push((Node){start, 0});
	while(!q.empty())
	{
		Node temp = q.top();q.pop();
		int u = temp.u;
		if(book[u]) continue;
		book[u] = true;
		for(int i = head[u];i;i = G[i].next)
		{
			int v = G[i].to;
			if(dis[u] + G[i].d < dis[v])
			{
				dis[v] = dis[u] + G[i].d;
				q.push((Node){v, dis[v]});
			}
		}
	}
}
void init()
{
	cnt = 0;
	memset(head, 0, sizeof(head));
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		dis[i] = INF;
	}
	// book[start] = true; // caution!
	dis[start] = 0;
}
int main()
{
	scanf("%d%d%d", &n, &m, &start);
	init();
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	dijkstra();
	for(int i = 1;i <= n;i++)
		printf("%d ", dis[i]);
	return 0;
}
