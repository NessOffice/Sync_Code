#include <cstdio>
#define ROOT 1
const int maxn = 1e5 + 5;
const int maxp = 1e7 + 1005;
struct Node{int l, r, w, f;}tree[4*maxn];
int x, y, ans, cnt, a[maxn], target;
char cmd;
int isPrime[maxp], prime[maxp];
void sift()
{
    for(int i = 0;i < maxp;i++)
        isPrime[i] = 1;
	isPrime[0] = 0;
	isPrime[1] = 0;
    int tot = 0;
	for(int i = 2;i <= maxp;i++)
    {
		if(isPrime[i]) prime[++tot] = i;
		for(int j = 1;j <= tot && i*prime[j] <= maxp;j++)
        {
			isPrime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}
void down(int k)
{
	int f = tree[k].f;
	tree[2*k].f = f;
	tree[2*k+1].f = f;
	tree[2*k].w = isPrime[f]*(tree[2*k].r - tree[2*k].l + 1);
	tree[2*k+1].w = isPrime[f]*(tree[2*k+1].r - tree[2*k+1].l + 1);
	tree[k].f = 0;
}
void operate(int k)
{
	if(x <= tree[k].l && tree[k].r <= y)
	{
		if(cmd == 'Q') ans += tree[k].w;
		if(cmd == 'R') tree[k].w = isPrime[target]*(tree[k].r - tree[k].l + 1);
		if(cmd == 'R') tree[k].f = target;
		if(cmd == 'A' && tree[k].f) a[x] = tree[k].f;
		if(cmd == 'A') cmd = 'R';
		return;
	}
	if(tree[k].f) down(k);
	int m = (tree[k].l+tree[k].r)/2;
	if(x <= m) operate(2*k);
	if(m < y) operate(2*k+1);
	if(cmd == 'R') tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
void build(int l, int r, int k)
{
	tree[k].l = l;
	tree[k].r = r;
	tree[k].f = 0;
	if(l == r)
	{
		scanf("%d", &a[++cnt]);
		tree[k].w = isPrime[a[cnt]];
		return;
	}
	int m = (l+r)/2;
	build(l, m, 2*k);
	build(m+1, r, 2*k+1);
	tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
int main()
{
	sift();
	int T, n, q;
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		scanf("%d%d", &n, &q);
		build(1, n, ROOT);
		while(q--)
		{
			int V, I;
			char temp[2];
			scanf("%s", &temp);
			cmd = temp[0];
			ans = 0;
			if(cmd == 'R')
				scanf("%d", &target);
			if(cmd == 'A'){
				scanf("%d%d", &V, &I);
				x = y = I;
				operate(ROOT);
				target = a[I]+V;
				operate(ROOT);
			}else{
				scanf("%d%d", &x, &y);
				operate(ROOT);
				if(cmd == 'Q')
					printf("%d\n", ans);
			}
		}
	}
	return 0;
}
