#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 4e6 + 10;
const int INF = 2147483647;
const int MOD = 100003;
int n, m;
int dis[MAXN], ans[MAXN];
bool book[MAXN];
struct Node{
	int u, d;
	bool operator < (const Node& rhs) const{return d > rhs.d;} // top: d is the smallest
};
struct Edge{
	int to;
	int next;
}G[MAXM];
int cnt, head[MAXN];
void add_edge(int u, int v)
{
	cnt++;
	G[cnt].to = v;
	G[cnt].next = head[u];
	head[u] = cnt;
}
void dijkstra()
{
	priority_queue<Node> q;
	q.push((Node){1, 0});
	while(!q.empty())
	{
		Node temp = q.top();q.pop();
		int u = temp.u;
		if(book[u]) continue;
		book[u] = true;
		for(int i = head[u];i;i = G[i].next)
		{
			int v = G[i].to;
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				ans[v] = ans[u];
				q.push((Node){v, dis[v]});
			}
			else if(dis[v] == dis[u] + 1)
			{
				ans[v] += ans[u];
				ans[v] %= MOD;
				// q.push((Node){v, dis[v]}); // no need
			}
		}
	}
}
void init()
{
	memset(head, 0, sizeof(head));
	memset(ans, 0, sizeof(ans));
	cnt = 0;
	ans[1] = 1;
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		dis[i] = INF;
	}
	dis[1] = 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	init();
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dijkstra();
	for(int i = 1;i <= n;i++)
		printf("%d\n", ans[i]);
	return 0;
}
