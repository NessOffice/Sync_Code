#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e5+5;
const LL INF = 1e9+7;
LL rd(){LL x;scanf("%lld", &x);return x;}
LL tree[maxn], num[maxn], ans[maxn], id[maxn], id_L[maxn], id_R[maxn], n, m, k;
vector<LL> country[maxn];
LL lowbit(LL x){return x&-x;}
LL add(LL begin, LL delta){for(LL i = begin;i < maxn;i += lowbit(i)) tree[i] += delta;}
void update(LL l, LL r, LL val)
{
    add(l, val);
    add(r+1LL, -val);
    if(l > r)
    {
        add(m+1LL, -val);
        add(1LL, val);
    }
}
LL query(LL begin){LL sum = 0;for(LL i = begin;i > 0;i -= lowbit(i)) sum += tree[i];return sum;}
struct Meteor{LL l, r, val;}meteors[maxn];
void solve(LL l, LL r, LL L, LL R)
{
    if(l > r || L > R) return;
    if(l == r)
    {
        for(LL i = L;i <= R;i++)
            ans[id[i]] = l;
        return;
    }
    LL mid = l + r >> 1LL, cnt_L = 0, cnt_R = 0;
    for(LL i = l;i <= mid;i++)
        update(meteors[i].l, meteors[i].r, meteors[i].val);
    for(LL i = L;i <= R;i++)
    {
        LL num_now = 0;
        for(LL j = country[id[i]].size()-1LL;j >= 0;j--)
        {
            num_now += query(country[id[i]][j]);
            if(num_now >= num[id[i]]) break;
        }
        if(num_now >= num[id[i]]) id_L[++cnt_L] = id[i];
        else num[id[i]] -= num_now, id_R[++cnt_R] = id[i];
    }
    for(LL i = l;i <= mid;i++)
        update(meteors[i].l, meteors[i].r, -meteors[i].val);
    for(LL i = 1LL;i <= cnt_L;i++)
        id[L+i-1LL] = id_L[i];
    for(LL i = 1LL;i <= cnt_R;i++)
        id[L+cnt_L+i-1LL] = id_R[i];
    solve(    l, mid,       L, L+cnt_L-1LL);
    solve(mid+1LL,   r, L+cnt_L,         R);
}
int main()
{
    // freopen("meteors.in", "r", stdin);
    // freopen("meteors.out", "w", stdout);
    n = rd(), m = rd();
    for(LL i = 1LL;i <= m;i++)
        country[rd()].push_back(i);
    for(LL i = 1LL;i <= n;i++)
        num[i] = rd(), id[i] = i;
    k = rd();
    for(LL i = 1LL;i <= k;i++)
        meteors[i].l = rd(), meteors[i].r = rd(), meteors[i].val = rd();
    meteors[++k].l = 1LL, meteors[k].r = m, meteors[k].val = INF;
    solve(1LL, k, 1LL, n);
    for(LL i = 1LL;i <= n;i++)
    {
        if(ans[i] != k)
            printf("%lld\n", ans[i]);
        else
            printf("NIE\n");
    }
    return 0;
}
