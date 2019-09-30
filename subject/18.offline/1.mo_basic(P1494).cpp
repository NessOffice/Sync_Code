#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e4+5;
struct Query{LL l, r, id;}queries[maxn];
struct Answer{LL p, q;}ans[maxn];
LL n, m, res, a[maxn], cnt[maxn], block_size, id_of_block[maxn];
bool cmp(const Query &lhs, const Query &rhs)
{
    if(id_of_block[lhs.l] != id_of_block[rhs.l])
        return id_of_block[lhs.l] < id_of_block[rhs.l];
    if(id_of_block[lhs.l] & 1)
        return lhs.r < rhs.r;
    else
        return lhs.r > rhs.r;
}
LL calc_C2(LL l, LL r){return (r-l+1)*(r-l);}
void update(LL col, LL flag)
{
    res -= (cnt[col]*(cnt[col]-1));
    cnt[col] += flag;
    res += (cnt[col]*(cnt[col]-1));
}
void get_ans(LL p, LL q, LL id)
{
    LL d = __gcd(p, q);
    if(q == 0){ans[id].p = 0, ans[id].q = 1;return;} // if q == 0
    ans[id].p = p / d;
    ans[id].q = q / d;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    block_size = n / (LL)(sqrt(m));
    for(LL i = 1;i <= n;i++)
        scanf("%lld", a + i),
        id_of_block[i] = (i-1)/block_size + 1;
    for(LL i = 1;i <= m;i++)
        scanf("%lld%lld", &queries[i].l, &queries[i].r),
        queries[i].id = i;
    sort(queries+1, queries+m+1, cmp);

    LL l = queries[1].l, r = queries[1].r;
    for(LL i = l;i <= r;i++)
        update(a[i], 1);
    get_ans(res, calc_C2(l, r) , queries[1].id);
    for(LL i = 2;i <= m;i++)
    {
        while(l < queries[i].l) update(a[l++], -1);
        while(l > queries[i].l) update(a[--l],  1);
        while(r < queries[i].r) update(a[++r],  1);
        while(r > queries[i].r) update(a[r--], -1);
        get_ans(res, calc_C2(l, r), queries[i].id);
    }
    for(LL i = 1;i <= m;i++)
        printf("%lld/%lld\n", ans[i].p, ans[i].q);
    return 0;
}
/*
6 6
1 2 3 3 3 2
2 6
2 2
1 3
3 5
1 6
4 4
*/