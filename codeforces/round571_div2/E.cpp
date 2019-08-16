#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e3+5;
LL n, m, q;
LL sum[2][maxn][maxn]; // 0 for original matrix while 1 for inversed matrix
LL get_flag(LL c)
{
    if(c == 0 || c == 1) return c;
    return 1^get_flag(c-(c&-c));
}
LL calc(LL r, LL c)
{
    LL ans = 0;
    ans += ((c/m)*(r/n)*sum[0][n][m]);
    LL dc = c % m, dr = r % n;
    LL flag_r = get_flag(r/n), flag_c = get_flag(c/m); // r/n for the number of fields behind
    ans += ((r/n+1)/2)*(sum[flag_c][n][dc]);
    ans += (r/n/2)*(sum[1^flag_c][n][dc]);
    ans += ((c/m+1)/2)*(sum[flag_r][dr][m]);
    ans += (c/m/2)*(sum[1^flag_r][dr][m]);
    ans += sum[flag_r^flag_c][dr][dc];
    return ans;
}
int main()
{
    char grids[maxn];
    scanf("%lld%lld%lld", &n, &m, &q);
    for(LL i = 1;i <= n;i++)
    {
        scanf("%s", grids+1);
        for(LL j = 1;j <= m;j++)
        {
            sum[0][i][j] = sum[0][i+n][j+m] = (grids[j] - '0');
            sum[0][i+n][j] = sum[0][i][j+m] = 1^(grids[j] - '0');
            sum[1][i][j] = sum[1][i+n][j+m] = 1^(grids[j] - '0');
            sum[1][i+n][j] = sum[1][i][j+m] = (grids[j] - '0');
        }
    }
    n *= 2, m *= 2; // basic unit: 2n*2m
    for(LL i = 1;i <= n;i++)
    for(LL j = 1;j <= m;j++)
    {
        sum[0][i][j] += (sum[0][i-1][j] + sum[0][i][j-1] - sum[0][i-1][j-1]);
        sum[1][i][j] += (sum[1][i-1][j] + sum[1][i][j-1] - sum[1][i-1][j-1]);
    }
    while(q--)
    {
        LL r1, r2, c1, c2;
        scanf("%lld%lld%lld%lld", &r1, &c1, &r2, &c2);
        printf("%lld\n", calc(r2, c2) + calc(r1-1, c1-1) - calc(r1-1, c2) - calc(r2, c1-1));
    }
    return 0;
}
/*
2 2 5
10
11
5 6 7 8
1 1 8 8
2 4 5 6
1 2 7 8
3 3 6 8
*/
