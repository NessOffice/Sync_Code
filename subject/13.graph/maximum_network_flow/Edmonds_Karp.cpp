#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = (1e5+5)*2;
struct Node{int to, val, nxt;}edges[maxn];
struct Path{int id, nxt;}path[maxn];
int n, m, st, ed, cnt;
int head[maxn];
bool vis[maxn];
void add_edge(int index, int u, int v, int val)
{
	edges[index].to = v;
	edges[index].val = val;
	edges[index].nxt = head[u];
	head[u] = index;
}
bool find_argumenting_path()
{
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	vis[st] = 1;
	q.push(st);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(int i = head[u];i != -1;i = edges[i].nxt)
		{
			int v = edges[i].to;
			if(vis[v]) continue;
			if(edges[i].val == 0) continue;
			path[v].nxt = u;
			path[v].id = i;
			vis[v] = 1;
			if(v == ed) return true;
			q.push(v);
		}
	}
	return false;
}
int edmonds_karp()
{
	int max_flow = 0, delta_flow = 1e9;
	while(find_argumenting_path())
	{
		for(int u = ed;u != st;u = path[u].nxt)
			delta_flow = min(delta_flow, edges[path[u].id].val);
		for(int u = ed;u != st;u = path[u].nxt)
		{
			edges[path[u].id].val -= delta_flow;
			edges[path[u].id^1].val += delta_flow;
		}
		max_flow += delta_flow;
	}
	return max_flow;
}
int main()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0;i < m;i++)
	{
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		add_edge(2*i, u, v, val);
		add_edge(2*i+1, v, u, 0);
	}
	printf("%d", edmonds_karp());
	return 0;
}
