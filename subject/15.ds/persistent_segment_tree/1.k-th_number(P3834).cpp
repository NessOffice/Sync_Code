#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
int cnt_of_tree, tree[maxn<<5], ltree[maxn<<5], rtree[maxn<<5], sum[maxn<<5];
int num[maxn], num_unique[maxn];
int build(int l, int r)
{
	int index = ++cnt_of_tree;
	if(l == r) return index;
	int mid = (l + r) >> 1;
	ltree[index] = build(l, mid);
	rtree[index] = build(mid+1, r);
	return index;
}
int update(int index_of_pre, int l, int r, int node_to_insert)
{
	int index = ++cnt_of_tree;
	ltree[index] = ltree[index_of_pre];
	rtree[index] = rtree[index_of_pre];
	sum[index] = sum[index_of_pre] + 1;
	if(l == r) return index;
	int mid = (l + r) >> 1;
	if(node_to_insert <= mid)
		ltree[index] = update(ltree[index_of_pre], l, mid, node_to_insert);
	else
		rtree[index] = update(rtree[index_of_pre], mid+1, r, node_to_insert);
	return index;
}
int query(int index_of_past, int index_of_now, int l, int r, int k)
{
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int num_of_lsons = sum[ltree[index_of_now]] - sum[ltree[index_of_past]];
	if(num_of_lsons >= k)
		return query(ltree[index_of_past], ltree[index_of_now], l, mid, k);
	else
		return query(rtree[index_of_past], rtree[index_of_now], mid+1, r, k-num_of_lsons);
}
int main()
{
    int n, n_unique, q;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", num + i);
		num_unique[i] = num[i];
	}
	sort(num_unique + 1, num_unique + n + 1);
	n_unique = unique(num_unique + 1, num_unique + n + 1) - num_unique - 1;
	tree[0] = build(1, n_unique);
	for(int i = 1;i <= n;i++)
	{
		int node_to_insert = lower_bound(num_unique + 1, num_unique + n_unique + 1, num[i]) - num_unique;
		tree[i] = update(tree[i-1], 1, n_unique, node_to_insert);
	}
	while(q--)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		printf("%d\n", num_unique[query(tree[x-1], tree[y], 1, n_unique, k)]);
	}
    return 0;
}
