#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5+5;
const int maxm = 1e5+5;
int l[maxn], r[maxn], deg_in[maxn], ans[maxn], vis[maxn];
vector<int> edge[maxn];
struct Node
{
	int l, r, id;
	bool operator < (const Node& rhs) const {return l > rhs.l;}
};
int get_r(int id)
{
	if(vis[id])
		return r[id];
	vis[id] = 1;
	for(int i = 0, sz = edge[id].size();i < sz;i++)
	{
		int u = edge[id][i];
		r[id] = min(r[id], get_r(u)-1);
	}
	return r[id];
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d%d", &l[i], &r[i]);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		deg_in[v]++;
	}
	priority_queue<Node> q_l;
	priority_queue<pair<int, int> >q_r;
	for(int i = 1;i <= n;i++)
	{
		r[i] = get_r(i);
		if(deg_in[i] == 0)
			q_l.push((Node){l[i], r[i], i});
	}
	int l_now = 1;
	while(1)
	{
		while(!q_l.empty() && q_l.top().l <= l_now)
		{
			q_r.push(make_pair(-q_l.top().r, q_l.top().id));
			q_l.pop();
		}
		if(q_r.empty()) break;
		int id_now = q_r.top().second;q_r.pop();
		if(r[id_now] < l_now) break;
		ans[l_now++] = id_now;
		for(int i = 0, sz = edge[id_now].size();i < sz;i++)
		{
			int u = edge[id_now][i];
			deg_in[u]--;
			if(deg_in[u] == 0)
				q_l.push((Node){l[u], r[u], u});
		}
	}
	if(l_now <= n)
		printf("-1\n");
	else for(int i = 1;i <= n;i++)
		printf("%d\n", ans[i]);
	return 0;
}
/*
3 3
1 3
1 3
1 3
1 2
2 3
1 3

3 3
1 3
1 3
1 3
1 2
2 3
3 1
*/