#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2e5 + 5;
const LL INF = 1e8;
LL lft[maxn], rgt[maxn], lft_col[maxn], rgt_col[maxn], dp[2][2];
bool safe_col[maxn];
LL ABS(LL num){return num > 0 ? num : -num;}
LL fun(LL val1, LL val2)
{
    if(lft_col[val1] >= val2) return ABS(val2 - val1);
    if(rgt_col[val1] <= val2) return ABS(val2 - val1);
    LL res1, res2;
    if(rgt_col[val1] == maxn) res1 = INF;
    else res1 = ABS(val2 - val1) + 2*ABS(rgt_col[val1] - max(val1, val2));
    if(lft_col[val1] == -1) res2 = INF;
    else res2 = ABS(val2 - val1) + 2*ABS(min(val1, val2) - lft_col[val1]);
    return min(res1, res2);
}
int main()
{
    LL n, m, k, q;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
    for(LL i = 1;i <= n;i++) lft[i] = maxn, rgt[i] = -1;
    while(k--)
    {
        LL ri, ci;
        scanf("%lld%lld", &ri, &ci);
        lft[ri] = min(lft[ri], ci);
        rgt[ri] = max(rgt[ri], ci);
    }
    while(q--)
    {
        LL bi;
        scanf("%lld", &bi);
        safe_col[bi] = true;
    }
    LL lst = -1;
    for(LL j = 1;j <= m;j++)
    {
        if(safe_col[j]) lst = j;
        lft_col[j] = lst;
    }
    lst = maxn;
    for(LL j = m;j >= 1;j--)
    {
        if(safe_col[j]) lst = j;
        rgt_col[j] = lst;
    }
    if(rgt[1] == -1) rgt[1] = 1;
    lft[1] = rgt[1];
    dp[1][0] = dp[1][1] = (rgt[1] - 1);
    LL now = 0, up = 1;
    for(LL i = 2;i <= n;i++)
    {
        if(lft[i] == maxn){up++;continue;}
        dp[now][0] = dp[now][1] = up + (rgt[i] - lft[i]);
        dp[now][0] += min(dp[now^1][0] + fun(lft[i-up], rgt[i]), dp[now^1][1] + fun(rgt[i-up], rgt[i]));
        dp[now][1] += min(dp[now^1][0] + fun(lft[i-up], lft[i]), dp[now^1][1] + fun(rgt[i-up], lft[i]));
        up = 1;
        now ^= 1;
    }
    printf("%lld", min(dp[now^1][0], dp[now^1][1]));
    return 0;
}
/*
3 5 2 2
1 2
2 3
1 5

3 6 3 2
1 6
2 2
3 4
1 6

3 5 3 2
1 2
2 3
3 1
1 5

3 3 3 2
1 1
2 1
3 1
2 3

3 3 1 1
2 1
3

3 3 2 2
1 1
3 1
2 3

5 3 10 3
5 3
1 1
2 2
1 3
3 2
5 2
2 3
2 1
3 1
5 1
1 2 3
*/