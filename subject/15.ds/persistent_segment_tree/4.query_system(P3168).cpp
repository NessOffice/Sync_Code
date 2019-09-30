#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2e2+5; //
pair<LL, LL> node[maxn];
LL cnt_of_tree, tree[maxn<<5], ltree[maxn<<5], rtree[maxn<<5], sum[maxn<<5], sz[maxn<<5];
LL num[maxn], num_unique[maxn];
LL update(LL index_of_pre, LL l, LL r, LL k, LL flag)
{
	LL index = ++cnt_of_tree;
	ltree[index] = ltree[index_of_pre];
	rtree[index] = rtree[index_of_pre];
	sz[index] = sz[index_of_pre] + flag;
	sum[index] = sum[index] + flag * k;
	if(l == r) return index;
	LL mid = (l + r) >> 1;
	if(k <= mid)
		ltree[index] = update(ltree[index_of_pre], l, mid, k, flag);
	else
		rtree[index] = update(rtree[index_of_pre], mid+1, r, k, flag);
	return index;
}
LL query(LL index_of_now, LL l, LL r, LL k)
{
	if(l == r) return sum[index_of_now] / sz[index_of_now] * k;
	LL mid = (l + r) >> 1;
	if(sz[index_of_now] >= k)
		return query(ltree[index_of_now], l, mid, k);
	else
		return query(rtree[index_of_now], mid+1, r, k - sz[index_of_now]) + sum[index_of_now];
}
int main()
{
    LL n, n_unique, q;
	scanf("%lld%lld", &n, &q);
	for(LL i = 1;i <= n;i++)
	{
		scanf("%lld%lld%lld", &node[2*i-1].first, &node[2*i].first, &node[2*i-1].second);
		node[2*i-1].first++;
		node[2*i].second = -node[2*i-1].second;
		num_unique[i] = node[2*i-1].second;
	}
	sort(num_unique + 1, num_unique + n + 1);
	sort(node+1, node+2*n+1);
	n_unique = unique(num_unique + 1, num_unique + n + 1) - (num_unique + 1);
	LL k = 1;
	for(LL i = 1;i <= n*2;i++)
	{
		while(k < node[i].first) tree[k+1] = tree[k], k++;
		if(k == n+1) break;
		LL k_origin = lower_bound(num_unique + 1, num_unique + n_unique + 1, abs(node[i].second)) - num_unique;
		tree[k] = update(tree[k], 1, n_unique, k_origin, node[i].second > 0 ? 1 : -1);
	}
	LL ans = 1;
	while(q--)
	{
		LL xi, ai, bi, ci;
		scanf("%lld%lld%lld%lld", &xi, &ai, &bi, &ci);
		LL ki = (ai * ans + bi) % ci + 1;
		printf("%lld\n", ans = query(tree[xi], 1, n_unique, ki));
	}
    return 0;
}
