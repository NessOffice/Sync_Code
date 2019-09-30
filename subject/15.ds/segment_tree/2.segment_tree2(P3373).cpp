#include <cstdio>
#define ROOT 1
typedef long long LL;
LL n, m, MOD;
const LL maxn = 1e5 + 7;
struct Node{LL l, r, w, lazy_mul, lazy_add;}tree[4*maxn];
LL cmd, x, y, d, ans;
void down(LL index)
{
    if(tree[index].l == tree[index].r) return;
    if(tree[index].lazy_add == 0 && tree[index].lazy_mul == 1) return;
    
    LL lazy_mul = tree[index].lazy_mul;
    LL lazy_add = tree[index].lazy_add;
    LL length1 = (tree[2*index].r - tree[2*index].l + 1);
    LL length2 = (tree[2*index+1].r - tree[2*index+1].l + 1);
    
    tree[2*index].w = tree[2*index].w * lazy_mul % MOD;
    tree[2*index].w = (tree[2*index].w + lazy_add*length1) % MOD;
    tree[2*index].lazy_mul = (tree[2*index].lazy_mul * lazy_mul) % MOD;
    tree[2*index].lazy_add = (tree[2*index].lazy_add * lazy_mul + lazy_add) % MOD;

    tree[2*index+1].w = tree[2*index+1].w * lazy_mul % MOD;
    tree[2*index+1].w = (tree[2*index+1].w + lazy_add*length2) % MOD;
    tree[2*index+1].lazy_mul = (tree[2*index+1].lazy_mul * lazy_mul) % MOD;
    tree[2*index+1].lazy_add = (tree[2*index+1].lazy_add * lazy_mul + lazy_add) % MOD;
    
    tree[index].lazy_mul = 1;
    tree[index].lazy_add = 0;
}
void operate(LL index)
{
    if(x <= tree[index].l && tree[index].r <= y)
    {
        if(cmd == 3) ans = (ans + tree[index].w) % MOD; //query

        if(cmd == 2) tree[index].w = (tree[index].w + d*(tree[index].r - tree[index].l + 1)) % MOD;
        if(cmd == 2) tree[index].lazy_add = (tree[index].lazy_add + d) % MOD; //add

        if(cmd == 1) tree[index].w = (tree[index].w * d) % MOD;
        if(cmd == 1) tree[index].lazy_mul = (tree[index].lazy_mul * d) % MOD;
        if(cmd == 1) tree[index].lazy_add = (tree[index].lazy_add * d) % MOD; //multiply

        return;
    }
    down(index);
    LL mid = (tree[index].l+tree[index].r)/2;
    if(x <= mid) operate(2*index);
    if(mid < y) operate(2*index+1);
    tree[index].w = (tree[2*index].w + tree[2*index+1].w) % MOD;
}
void build(LL index, LL l, LL r)
{
    tree[index].l = l;
    tree[index].r = r;
    tree[index].lazy_mul = 1;
    tree[index].lazy_add = 0;
    if(l == r)
    {
        LL temp;
        scanf("%lld", &temp);
        tree[index].w = temp % MOD;
        return;
    }
    LL mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    tree[index].w = (tree[2*index].w + tree[2*index+1].w) % MOD;
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &MOD);
    build(ROOT, 1, n);
    while(m--)
    {
        scanf("%lld%lld%lld", &cmd, &x, &y);
        if(cmd != 3){scanf("%lld", &d);d %= MOD;}
        else ans = 0;
        operate(ROOT);
        if(cmd == 3) printf("%lld\n", ans);
    }
    return 0;
}