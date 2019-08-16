#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5+5;
const int maxv = 1e6+5;
int n, m, q, a[maxn], b[maxn];
struct Node{int l, r, v, lazy;}tree[4*maxv];
void down(int index);
void build(int index, int l, int r)
{
    tree[index].l = l;
    tree[index].r = r;
    if(l == r) return;
    int mid = (l + r) / 2;
    build(index << 1, l, mid);
    build((index << 1)+1, mid+1, r);
}
void change(int index, int target, int mark) // mark == 1 ? meal : pupil
{
    if(tree[index].r <= target)
    {
        tree[index].v += mark;
        tree[index].lazy += mark;
        return;
    }
    down(index);
    int mid = (tree[index].l + tree[index].r) / 2;
    change(index << 1, target, mark);
    if(target > mid)
        change((index << 1)+1, target, mark);
    tree[index].v = max(tree[index<<1].v, tree[(index<<1)+1].v);
}
int ask()
{
    int index = 1;
    while(tree[index].l != tree[index].r)
    {
        down(index);
        if(tree[(index<<1)+1].v > 0)
            index = (index<<1)+1;
        else
            index <<= 1;
    }
    return (tree[index].v > 0) ? tree[index].l : -1;
}
int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, maxv-1);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", a+i);
        change(1, a[i], 1);
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d", b+i);
        change(1, b[i], -1);
    }
    scanf("%d", &q);
    while(q--)
    {
        int cmd, i2, x, *c, mark;
        scanf("%d%d%d", &cmd, &i2, &x);
        c = (cmd == 1) ? a : b;
        mark = (cmd == 1) ? 1 : -1;

        change(1, *(c+i2), -mark);
        *(c+i2) = x;
        change(1, *(c+i2), mark);
        
        printf("%d\n", ask());
    }
    return 0;
}
void down(int index)
{
    if(tree[index].l == tree[index].r) return;
    if(tree[index].lazy == 0) return;
    int mid = (tree[index].l + tree[index].r) / 2;
    change(index << 1, mid, tree[index].lazy);
    change((index<<1)+1, tree[index].r, tree[index].lazy);
    tree[index].lazy = 0;
}