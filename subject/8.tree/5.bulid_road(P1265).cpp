#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 5e3 + 10;
const int INF = 2147483647;
int num_of_vertice;
int n, m, start;
int x[MAXN], y[MAXN];
double dis[MAXN], ans;
bool book[MAXN];
double dist(int x1, int y1, int x2, int y2)
{
	return sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}
struct Node{
	int u;
	double w;
	bool operator < (const Node& rhs) const{return w > rhs.w;} // top: w is the smallest
};
void prim()
{
	priority_queue<Node> q;
	q.push((Node){start, dis[start]});
	while(!q.empty())
	{
		Node temp = q.top();q.pop();
		int u = temp.u;
		if(book[u]) continue;
		book[u] = true;
		ans += temp.w;
		num_of_vertice++;
		for(int v = 1;v <= n;v++)
		{
			if(!book[v] && dis[v] > dist(x[u], y[u], x[v], y[v]))
			{
				dis[v] = dist(x[u], y[u], x[v], y[v]);
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
	num_of_vertice = 0;
	ans = 0.0;
	for(int i = 1;i <= n;i++)
	{
		book[i] = false;
		dis[i] = INF;
	}
	dis[start] = 0;
}
int main()
{
	scanf("%d", &n);
	init();
	for(int i = 1;i <= n;i++)
		scanf("%d%d", &x[i], &y[i]);
	prim();
	printf("%.2lf\n", ans);
	return 0;
}
