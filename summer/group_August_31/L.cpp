#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
namespace SegmentTree
{
    struct Tree{LL l, r, sum, val, tag;}tree[maxn<<2];

    void pushup(LL id)
    {
        tree[id].sum = 0;
        tree[id].val = min(tree[id<<1].val, tree[id<<1|1].val);
        if(tree[id].val == tree[id<<1].val) tree[id].sum += tree[id<<1].sum;
        if(tree[id].val == tree[id<<1|1].val) tree[id].sum += tree[id<<1|1].sum;
    }

    void pushdown(LL id)
    {
        if(!tree[id].tag) return;
        tree[id<<1].val += tree[id].tag;
        tree[id<<1|1].val += tree[id].tag;
        tree[id<<1].tag += tree[id].tag;
        tree[id<<1|1].tag += tree[id].tag;
        tree[id].tag = 0;
    }

    void build(LL id, LL l, LL r)
    {
        tree[id] = (Tree){l, r, 0, 0, 0};
        if(l == r){tree[id].sum = 1;return;}
        LL mid = l + r >> 1;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        pushup(id);
    }

    void update(LL id, LL l, LL r, LL delta)
    {
        if(l <= tree[id].l && tree[id].r <= r)
        {
            tree[id].val += delta;
            tree[id].tag += delta;
            return;
        }
        pushdown(id);
        LL mid = tree[id].l + tree[id].r >> 1;
        if(l <= mid) update(id<<1, l, r, delta);
        if(mid < r) update(id<<1|1, l, r, delta);
        pushup(id);
    }

    LL query(LL id, LL l, LL r)
    {
        // printf("[Query] id: %lld, l: %lld, r:%lld sum:%lld, val:%lld\n", id, l, r, tree[id].sum, tree[id].val);
        if(l <= tree[id].l && tree[id].r <= r)
            return tree[id].val == -1 ? tree[id].sum : 0;
        pushdown(id);
        LL ans = 0;
        LL mid = tree[id].l + tree[id].r >> 1;
        if(l <= mid) ans += query(id<<1, l, r);
        if(mid < r) ans += query(id<<1|1, l, r);
        return ans;
    }
}
struct Node{LL pos, val;}sta[2][maxn];
LL top[2];
map<LL, LL> last;
int main()
{
    LL T;
    scanf("%lld", &T);
    for(LL kase = 1;kase <= T;kase++)
    {
        LL n, res = 0;
        scanf("%lld", &n);
        SegmentTree::build(1, 1, n);
        top[0] = top[1] = 0;
        last.clear();
        for(LL i = 1;i <= n;i++)
        {
            LL ai;
            scanf("%lld", &ai);
            while(top[0] && sta[0][top[0]].val < ai)
            {
                LL delta = ai - sta[0][top[0]].val;
                SegmentTree::update(1, sta[0][top[0]-1].pos+1, sta[0][top[0]].pos, delta);
                top[0]--;
            }
            sta[0][++top[0]] = (Node){i, ai};
            while(top[1] && sta[1][top[1]].val > ai)
            {
                LL delta = sta[1][top[1]].val - ai;
                SegmentTree::update(1, sta[1][top[1]-1].pos+1, sta[1][top[1]].pos, delta);
                top[1]--;
            }
            sta[1][++top[1]] = (Node){i, ai};
            SegmentTree::update(1, last[ai]+1, i, -1);
            last[ai] = i;
            res += SegmentTree::query(1, 1, i);
        }
        printf("Case #%lld: %lld\n", kase, res);
    }
    return 0;
}
