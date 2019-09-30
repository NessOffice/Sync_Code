#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e3 + 5;
LL num[maxn][maxn];
LL dp[maxn][13]; // 2**12 = 4096 > 3000
LL rmq[maxn][maxn];
LL ans[2][maxn][maxn];
LL query(LL t, LL l, LL r)
{
    LL len = (r - l + 1), step = 0, res = 0;
    while((1<<(step+1)) <= len) step++;
    res = dp[l][step];
    if((1<<step) != len)
    {
        if(t) res = max(res, query(t, l+(1<<step), r));
        else  res = min(res, query(t, l+(1<<step), r));
    }
    return res;
}
void calc_dp(LL t, LL border)
{
    for(LL step = 1;(1<<step) <= border;step++)
    {
        LL jmp = (1<<step);
        for(LL j = 1;j + jmp - 1 <= border;j++)
            if(t) dp[j][step] = max(dp[j][step-1], dp[j+(jmp>>1)][step-1]);
            else  dp[j][step] = min(dp[j][step-1], dp[j+(jmp>>1)][step-1]);
    }
}
int main()
{
    LL a, b, n, a_new, b_new, res = 1e9+7;
    scanf("%lld%lld%lld", &a, &b, &n);
    a_new = a - n + 1, b_new = b - n + 1;
    for(LL i = 1;i <= a;i++)
    for(LL j = 1;j <= b;j++)
        scanf("%lld", &num[i][j]);
    for(LL t = 0;t < 2;t++) // calc max or min
    {
        for(LL i = 1;i <= a;i++)
        {
            for(LL j = 1;j <= b;j++)
                dp[j][0] = num[i][j];
            calc_dp(t, b);
            for(LL j = 1;j <= b_new;j++)
                rmq[i][j] = query(t, j, j + n - 1);
        }
        for(LL j = 1;j <= b_new;j++)
        {
            for(LL i = 1;i <= a;i++)
                dp[i][0] = rmq[i][j];
            calc_dp(t, a);
            for(LL i = 1;i <= a_new;i++)
                ans[t][i][j] = query(t, i, i + n - 1);
        }
    }
    for(LL i = 1;i <= a_new;i++)
    for(LL j = 1;j <= b_new;j++)
        res = min(res, ans[1][i][j] - ans[0][i][j]);
    printf("%lld", res);
    return 0;
}
