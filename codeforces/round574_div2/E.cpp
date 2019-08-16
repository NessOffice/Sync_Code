#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e3 + 5;
LL dp[maxn][13]; // 2**12 = 4096 > 3000
LL rmq[maxn][maxn];
LL query(LL l, LL r)
{
    LL len = (r - l + 1), step = 0, ans = 0;
    while((1<<(step+1)) <= len) step++;
    ans = dp[l][step];
    if((1<<step) != len)
        ans = min(ans, query(l+(1<<step), r));
    return ans;
}
void calc_dp(LL border)
{
    for(LL step = 1;(1<<step) <= border;step++)
    {
        LL jmp = (1<<step);
        for(LL j = 1;j + jmp - 1 <= border;j++)
            dp[j][step] = min(dp[j][step-1], dp[j+(jmp>>1)][step-1]);
    }
}
int main()
{
    LL n, m, a, b, n_new, m_new, res = 0;
    scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
    n_new = n - a + 1, m_new = m - b + 1;
    LL g0, x, y, z;
    scanf("%lld%lld%lld%lld", &g0, &x, &y, &z);
    for(LL i = 1;i <= n;i++)
    {
        for(LL j = 1;j <= m;j++)
        {
            dp[j][0] = g0;
            g0 = (x * g0 + y) % z;
        }
        calc_dp(m);
        for(LL j = 1;j <= m_new;j++)
            rmq[i][j] = query(j, j + b - 1);
    }
    for(LL j = 1;j <= m_new;j++)
    {
        for(LL i = 1;i <= n;i++)
            dp[i][0] = rmq[i][j];
        calc_dp(n);
        for(LL i = 1;i <= n_new;i++)
            res += query(i, i + a - 1);
    }
    printf("%lld", res);
    return 0;
}
