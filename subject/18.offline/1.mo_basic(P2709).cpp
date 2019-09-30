#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e4+5;
struct Query{LL l, r, id;}queries[maxn];
LL n, m, k, res, a[maxn], cnt[maxn], ans[maxn], block_size, id_of_block[maxn];
bool cmp(const Query &lhs, const Query &rhs)
{
    if(id_of_block[lhs.l] != id_of_block[rhs.l])
        return id_of_block[lhs.l] < id_of_block[rhs.l];
    if(id_of_block[lhs.l] & 1)
        return lhs.r < rhs.r;
    else
        return lhs.r > rhs.r;
}
void update(LL col, LL flag)
{
    res = res + 2*flag*cnt[col] + 1;
    cnt[col] += flag;
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
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
    ans[queries[1].id] = res;
    for(LL i = 2;i <= m;i++)
    {
        while(l < queries[i].l) update(a[l++], -1);
        while(l > queries[i].l) update(a[--l],  1);
        while(r < queries[i].r) update(a[++r],  1);
        while(r > queries[i].r) update(a[r--], -1);
        ans[queries[i].id] = res;
    }
    for(LL i = 1;i <= m;i++)
        printf("%lld\n", ans[i]);
    return 0;
}
