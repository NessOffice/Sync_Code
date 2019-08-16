#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6+5;
int cnt_of_tree, tree[maxn<<5], ltree[maxn<<5], rtree[maxn<<5], val[maxn<<5];
int num[maxn];
int build(int l, int r)
{
	int index = ++cnt_of_tree;
	if(l == r){val[index] = num[l];return index;}
	int mid = (l + r) >> 1;
	ltree[index] = build(l, mid);
	rtree[index] = build(mid+1, r);
	return index;
}
int update(int index_of_pre, int l, int r, int loc, int node_to_update)
{
	int index = ++cnt_of_tree;
	ltree[index] = ltree[index_of_pre];
	rtree[index] = rtree[index_of_pre];
	val[index] = val[index_of_pre];
	if(l == r){val[index] = node_to_update;return index;}
	int mid = (l + r) >> 1;
	if(loc <= mid)
		ltree[index] = update(ltree[index_of_pre], l, mid, loc, node_to_update);
	else
		rtree[index] = update(rtree[index_of_pre], mid+1, r, loc, node_to_update);
	return index;
}
int query(int index, int l, int r, int loc)
{
	if(l == r) return val[index];
	int mid = (l + r) >> 1;
	if(loc <= mid)
		return query(ltree[index], l, mid, loc);
	else
		return query(rtree[index], mid+1, r, loc);
}
int main()
{
    int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++)
		scanf("%d", num + i);
	tree[0] = build(1, n);
	for(int i = 1;i <= q;i++)
	{
		int version, cmd, loc, val_new;
		scanf("%d%d%d", &version, &cmd, &loc);
		if(cmd == 1){scanf("%d", &val_new);tree[i] = update(tree[version], 1, n, loc, val_new);}
		if(cmd == 2){printf("%d\n", query(tree[version], 1, n, loc));tree[i] = tree[version];}
	}
    return 0;
}
