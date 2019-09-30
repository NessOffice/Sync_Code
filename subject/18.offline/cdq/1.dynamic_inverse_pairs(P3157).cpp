#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e5 + 5; // caution
LL rd(){LL x;scanf("%lld", &x);return x;}
struct Node{LL pos, val, id, type;}node[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.pos < rhs.pos;}
LL lowbit(LL num){return (num & -num);}
LL cnt, n, m, tree[2*maxn], ans[maxn], val2pos[maxn];
void add(LL index, LL num){for(;index <= n;index += lowbit(index)) tree[index] += num;}
LL query(LL begin){LL ans = 0;for(LL i = begin;i > 0;i -= lowbit(i)) ans += tree[i];return ans;}
void cdq(LL l, LL r)
{
	if(l == r) return;
	LL mid = (l+r)/2;
	cdq(l, mid);
	cdq(mid+1, r);
	sort(node + l, node + mid+1, cmp);
	sort(node + mid+1, node + r+1, cmp);
	LL ptrl = l;
	for(LL ptrr = mid+1;ptrr <= r;ptrr++)
	{
		while(ptrl <= mid && (node[ptrl].pos <= node[ptrr].pos))
			add(node[ptrl].val, node[ptrl].type), ptrl++;
		ans[node[ptrr].id] += node[ptrr].type*(query(n) - query(node[ptrr].val));
	}
	for(LL ptr = l;ptr < ptrl;ptr++)
		add(node[ptr].val, -node[ptr].type);
	ptrl = mid;
	for(LL ptrr = r;ptrr > mid;ptrr--)
	{
		while(ptrl >= l && (node[ptrl].pos >= node[ptrr].pos))
			add(node[ptrl].val, node[ptrl].type), ptrl--;
		ans[node[ptrr].id] += node[ptrr].type*query(node[ptrr].val-1);
	}
	for(LL ptr = mid;ptr > ptrl;ptr--)
		add(node[ptr].val, -node[ptr].type);
}
int main()
{
	n = rd(), m = rd();
	for(LL i = 1;i <= n;i++)
	{
		LL val = rd();
		val2pos[val] = i;
		node[++cnt] = (Node){i, val, 0, 1};
	}
	for(LL i = 1;i <= m;i++)
	{
		LL val = rd();
		node[++cnt] = (Node){val2pos[val], val, i, -1};
	}
	cdq(1, cnt);
	for(LL i = 1;i <= m;i++)
		ans[i] += ans[i-1];
	for(LL i = 0;i < m;i++)
		printf("%lld\n", ans[i]);
    return 0;
}
