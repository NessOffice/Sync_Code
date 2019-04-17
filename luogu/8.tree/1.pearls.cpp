#include <cstdio>
#include <algorithm>
using namespace std;
#define ROOT 1
typedef long long LL;
const LL maxn = 5e5 + 7;
struct Node{LL l, r, w, f;}tree[4*maxn];
struct Section{LL l, r, index, res;}sections[maxn];
LL cmd, x, y, d, ans, cnt = 0, a[maxn];
bool cmp1(const Section& lhs, const Section& rhs){return lhs.r < rhs.r || (lhs.r == rhs.r && lhs.l < rhs.l);}
bool cmp2(const Section& lhs, const Section& rhs){return lhs.index < rhs.index;}
void operate(LL k)
{
	if(x <= tree[k].l && tree[k].r <= y)
	{
		if(cmd == 2) ans += tree[k].w;
		if(cmd == 1) tree[k].w += d;
		return;
	}
	LL m = (tree[k].l+tree[k].r)/2;
	if(x <= m) operate(2*k);
	if(m < y) operate(2*k+1);
	if(cmd == 1) tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
void build(LL l, LL r, LL k)
{
	tree[k].l = l;
	tree[k].r = r;
	if(l == r)
	{
		scanf("%lld", &a[++cnt]);
		tree[k].w = 1;
		return;
	}
	LL m = (l+r)/2;
	build(l, m, 2*k);
	build(m+1, r, 2*k+1);
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
int main()
{
	LL n, m;
	scanf("%lld%lld", &n);
	build(1, n, ROOT);
	scanf("%lld", &m);
	for(LL i = 0;i < m;i++)
	{
		scanf("%lld%lld", &sections[i].l, &sections[i].r);
		sections[i].index = i;
	}
	sort(sections, sections + m, cmp1);
	
	sort(sections, sections + m, cmp2);
	for(LL i = 0;i < m;i++)
		printf("%lld\n", sections[i].res);
	return 0;
}
