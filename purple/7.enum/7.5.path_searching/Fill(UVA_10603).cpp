#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 200 + 5;
int cap[3], ans[maxn];
int vis[maxn][maxn], dist[maxn][maxn];
struct Node{
	int v[3], dist;
	bool operator < (const Node& u2) const{return dist > u2.dist;}//const?
};
void print_ans(int d)
{
	for(int i = d;i >= 0;i--)
		if(ans[i] != -1){printf("%d %d\n", ans[i], i);return;}
}
void update_ans(const Node& u)
{
	for(int i = 0;i < 3;i++)
	if(ans[u.v[i]] == -1 || u.dist < ans[u.v[i]])
		ans[u.v[i]] = u.dist;
}
void solve(int a, int b, int c, int d)
{
	cap[0] = a, cap[1] = b, cap[2] = c;
	memset(ans, -1, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	memset(dist, -1, sizeof(dist));
	priority_queue<Node> q; 
	Node begin;
	begin.v[0] = begin.v[1] = begin.dist = 0, begin.v[2] = c;
	q.push(begin);
	while(!q.empty())
	{
		Node u = q.top();q.pop();
		if(vis[u.v[0]][u.v[1]]) continue;
		vis[u.v[0]][u.v[1]] = 1;
		update_ans(u);
		if(ans[d] != -1) break;
		for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
		{
			if(j == i || u.v[i] == 0 || u.v[j] == cap[j]) continue;
			int amount = min(u.v[i], cap[j] - u.v[j]);
			Node u2;
			memcpy(&u2, &u, sizeof(u));
			u2.v[i] -= amount;
			u2.v[j] += amount;
			u2.dist = u.dist + amount;
			int& D = dist[u2.v[0]][u2.v[1]];
			if(D == -1 || u2.dist < D) D = u2.dist, q.push(u2);
		}
	}
	print_ans(d);
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int a, b, c, d, n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		solve(a, b, c, d);
	}
	return 0;
}
