#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5; // caution
int n, q, root, MOD;
int val_of_node[maxn], val_of_index[maxn];
int tree_val[maxn<<2], tree_tag[maxn<<2];
void update_node(int index, int l, int r, int val)
{
	tree_val[index] = (tree_val[index] + (r - l + 1) * val) % MOD;
	tree_tag[index] += val;
}
void pushdown(int index, int l, int r)
{
	int tag = tree_tag[index];
	if(tag == 0) return;
	if(l == r) return;
	int mid = (l + r) >> 1;
	update_node(2*index, l, mid, tag);
	update_node(2*index+1, mid+1, r, tag);
	
	tree_tag[index] = 0;
}
int operate(int index, int l, int r, int x, int y, int val, int cmd) // including "add" and "query"
{
	int ans = 0;
	if(x <= l && r <= y)
	{
		if(cmd == 'a') update_node(index, l, r, val);
		ans = (ans + tree_val[index]) % MOD;
		return ans;
	}
	pushdown(index, l, r);
	int mid = (l + r) >> 1;
	if(mid >= x) ans = (ans + operate(2*index, l, mid, x, y, val, cmd)) % MOD;
	if(mid < y) ans = (ans + operate(2*index+1, mid+1, r, x, y, val, cmd)) % MOD;
	tree_val[index] = (tree_val[2*index] + tree_val[2*index+1]) % MOD;
	return ans;
}
void build(int index, int l, int r)
{
	if(l == r)
	{
		tree_val[index] = val_of_index[l] % MOD;
		return;
	}
	int mid = (l + r) >> 1;
	build(2*index, l, mid);
	build(2*index+1, mid+1, r);
	tree_val[index] = (tree_val[2*index] + tree_val[2*index+1]) % MOD;
}
// ------------------ above: segment tree ------------------
int head[maxn], to[maxn], nxt[maxn], cnt_of_edge;
void add_edge(int u, int v)
{
	cnt_of_edge++;
	to[cnt_of_edge] = v;
	nxt[cnt_of_edge] = head[u];
	head[u] = cnt_of_edge;
}
int depth[maxn], sz[maxn], parent[maxn], heavy[maxn];
void dfs_getinfo(int u, int deep)
{
	depth[u] = deep;
	sz[u] = 1;
	int sz_of_heavy = -1;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(depth[v]) continue;
		parent[v] = u;
		dfs_getinfo(v, deep + 1);
		sz[u] += sz[v];
		if(sz[v] > sz_of_heavy)
			sz_of_heavy = sz[v], heavy[u] = v;
	}
}
int id[maxn], top[maxn], cnt_of_list;
void dfs_getlist(int u, int top_now)
{
	id[u] = ++cnt_of_list;
	top[u] = top_now;
	val_of_index[id[u]] = val_of_node[u];
	if(heavy[u])
		dfs_getlist(heavy[u], top_now);
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(id[v]) continue;
		dfs_getlist(v, v);
	}
}
int find_path(int u, int v, int val, int cmd) // including "add" and "query"
{
	int ans = 0;
	while(top[u] != top[v])
	{
		if(depth[top[u]] < depth[top[v]]) swap(u, v);
		if(cmd == 'a') operate(1, 1, n, id[top[u]], id[u], val, 'a');
		if(cmd == 'q') ans = (ans + operate(1, 1, n, id[top[u]], id[u], 0, 'q')) % MOD;
		u = parent[top[u]];
	}
	if(depth[u] < depth[v]) swap(u, v);
	if(cmd == 'a') operate(1, 1, n, id[v], id[u], val, 'a');
	if(cmd == 'q') ans = (ans + operate(1, 1, n, id[v], id[u], 0, 'q')) % MOD;
	return ans;
}
int main()
{
    scanf("%d%d%d%d", &n, &q, &root, &MOD);
	for(int i = 1;i <= n;i++)
		scanf("%d", val_of_node + i);
	for(int i = 0;i < n-1;i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	parent[root] = root;
	dfs_getinfo(root, 1);
	dfs_getlist(root, root);
	build(1, 1, n);
	while(q--)
	{
		int cmd, u, v, val, x, y;
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1:
				scanf("%d%d%d", &u, &v, &val);
				find_path(u, v, val, 'a');
				break;
			case 2:
				scanf("%d%d", &u, &v);
				printf("%d\n", find_path(u, v, 0, 'q'));
				break;
			case 3:
				scanf("%d%d", &u, &val);
				x = id[u], y = id[u] + sz[u] - 1;
				operate(1, 1, n, x, y, val, 'a');
				break;
			case 4:
				scanf("%d", &u);
				x = id[u], y = id[u] + sz[u] - 1;
				printf("%d\n", operate(1, 1, n, x, y, 0, 'q'));
				break;
		}
	}
    return 0;
}

/*
8 8 2 448348
458 718 447 857 633 264 238 944 
1 2
2 3
3 4
6 2
1 5
5 7
8 6
3 7 611
4 6
3 1 267
3 2 111
1 6 3 153
3 7 673
4 8
4 7

8 10 2 448348
458 718 447 857 633 264 238 944 
1 2
2 3
3 4
6 2
1 5
5 7
8 6
3 7 611
4 6
3 1 267
3 2 111
1 6 3 153
3 7 673
4 8
2 6 1
4 7
3 4 228

*/