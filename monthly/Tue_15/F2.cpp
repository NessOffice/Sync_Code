#include <cstdio>
#include <cstring>
#define ROOT 1
const int maxn = 1e3 + 5;//
const int maxp = 1e7 + 5;
int isPrime[maxp], prime[maxp];
int x, y, ans, cnt, target, A[maxn];
char type;
struct Node{int l, r, w, f;}tree[4*maxn];
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
    if(type == 'A' && tree[k].l == tree[k].r && x == y && tree[k].f)
    {
        A[x] = tree[k].f;
        tree[k].f = 0;
        return;
    }
    if(x <= tree[k].l && tree[k].r <= y)
    {
        if(type == 'Q') ans += tree[k].w;
        else tree[k].f = target;
        return;
    }
    if(tree[k].f) down(k);
    int m = (tree[k].l + tree[k].r)/2;
    if(x <= m) operate(2*k);
    if(y > m) operate(2*k+1);
    if(type == 'A') tree[k].w = tree[2*k].w + tree[2*k+1].w;
}
void build(int l, int r, int k)
{
    tree[k].l = l;
    tree[k].r = r;
    if(l == r)
    {
        scanf("%d", &A[++cnt]);
        tree[k].w = isPrime[A[cnt]];
        return;
    }
    int m = (l+r)/2;
    build(l, m, 2*k);
    build(m+1, r, 2*k+1);
    tree[k].w = tree[2*k].w + tree[2*k+1].w;
    tree[k].f = 0;
}
int main()
{
    sift();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        cnt = 0;
        int n, q;
        scanf("%d%d", &n, &q);
        build(1, n, ROOT);
        while(q--)
        {
            char op[2];
            int V, I;
            scanf("%s", &op);
            type = op[0];
            switch(type)
            {
                case 'Q':
                    scanf("%d%d", &x, &y);
                    ans = 0;
                    operate(ROOT);
                    printf("%d\n", ans);
                break;
                case 'A':
                    scanf("%d%d", &V, &I);
                    x = y = I;
                    operate(ROOT);//update A[I];
                    target = A[I]+V;
                    operate(ROOT);
                break;
                case 'r':
                    scanf("%d%d%d", &target, &x, &y);
                    operate(ROOT);
                break;
            }
        }
    }
    return 0;
}