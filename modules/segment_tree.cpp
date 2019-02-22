#include <cstdio>
#define ROOT 1
typedef long long LL;
const LL maxn = 1e5 + 7;
struct Node{LL l, r, w, f;}tree[4*maxn];
LL cmd, x, y, d, ans, cnt = 0, a[maxn];
void down(LL k)
{
	LL f = tree[k].f;
	tree[2*k].f += f;
	tree[2*k+1].f += f;
	tree[2*k].w += f*(tree[2*k].r - tree[2*k].l + 1);
	tree[2*k+1].w += f*(tree[2*k+1].r - tree[2*k+1].l + 1);
	tree[k].f = 0;
}
void operate(LL k)
{
	if(x <= tree[k].l && tree[k].r <= y)
	{
		if(cmd == 2) ans += tree[k].w;
		if(cmd == 1) tree[k].w += d*(tree[k].r - tree[k].l + 1);
		if(cmd == 1) tree[k].f += d;
		return;
	}
	if(tree[k].f) down(k);
	LL m = (tree[k].l+tree[k].r)/2;
	if(x <= m) operate(2*k);
	if(m < y) operate(2*k+1);
	if(cmd == 1) tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
void build(LL l, LL r, LL k)
{
	tree[k].l = l;
	tree[k].r = r;
	tree[k].f = 0;
	if(l == r)
	{
		scanf("%lld", &a[++cnt]);
		tree[k].w = a[cnt];
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
	scanf("%lld%lld", &n, &m);
	build(1, n, ROOT);
	while(m--)
	{
		scanf("%lld%lld%lld", &cmd, &x, &y);
		if(cmd == 1)
			scanf("%lld", &d);
		ans = 0;
		operate(ROOT);
		if(cmd == 2)
			printf("%lld\n", ans);
	}
	return 0;
}
