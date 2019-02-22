#include <cstdio>
#include <cstring>
#define ROOT 1
const int maxn = 1e3 + 5;//
const int maxp = 1e7 + 5;
int isPrime[maxp], prime[maxp];
int cnt, target, A[maxn];
struct Node{int L, R, w, f;}tree[4*maxn];
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
    tree[2*k].w = isPrime[f]*(tree[2*k].R - tree[2*k].L + 1);
    tree[2*k+1].w = isPrime[f]*(tree[2*k+1].R - tree[2*k+1].L + 1);
    tree[k].f = 0;
}
int query(int L, int R, int k)
{
    if(tree[k].f)
    {
        if(L == R && tree[k].L == tree[k].R)
            A[L] = tree[k].f;
        else down(k);
    }
    if(L == tree[k].L && R == tree[k].R)
        return tree[k].w;
    int mid = (tree[k].L + tree[k].R)/2;
    if(L > mid)
        return query(L, R, 2*k+1);
    if(R <= mid)
        return query(L, R, 2*k);
    return query(L, mid, 2*k) + query(mid+1, R, 2*k+1);
}
void change(int L, int R, int k)
{
    if(L == tree[k].L && R == tree[k].R)
    {
        tree[k].f = target;
        return;
    }
    int mid = (tree[k].L + tree[k].R)/2;
    if(L > mid){change(L, R, 2*k+1);return;}
    if(R <= mid){change(L, R, 2*k);return;}
    change(L, mid, 2*k);
    change(mid+1, R, 2*k+1);
}
void build(int L, int R, int k)
{
    tree[k].L = L;
    tree[k].R = R;
    if(L == R)
    {
        scanf("%d", &A[++cnt]);
        tree[k].w = isPrime[A[cnt]];
        return;
    }
    int mid = (L+R)/2;
    build(L, mid, 2*k);
    build(mid+1, R, 2*k+1);
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
            int V, I, a, L, R;
            scanf("%s", &op);
            switch(op[0])
            {
                case 'Q':
                    scanf("%d%d", &L, &R);
                    printf("%d\n", query(L, R, ROOT));
                break;
                case 'A':
                    scanf("%d%d", &V, &I);
                    query(I, I, ROOT);//update A[I];
                    target = A[I]+V;
                    change(I, I, ROOT);
                break;
                case 'R':
                    scanf("%d%d%d", &a, &L, &R);
                    target = a;
                    change(L, R, ROOT);
                break;
            }
        }
    }
    return 0;
}