#include <cstdio>
#include <cstring>
const int MOD = 1000000007;
const int maxn = 1e6 + 5;
int n, dp[maxn][21][2]; // 2^21 = 2097152 > maxn, fuck! 1e6...not 1e5
// dp[i][x][y]: the number of GOOD permutaions(part) with index up to i and gcd equal with (2^x * 3^y)
int cnt(int x, int y)
{
    int num = n;
    while(x--)
        num /= 2;
    while (y--)
        num /= 3;
    return num;
}
int main()
{
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    int max_x = 0;
    while((1 << (max_x+1)) <= n) max_x++;
    dp[1][max_x][0] = 1;
    if((1 << (max_x-1))*3 <= n)
        dp[1][max_x-1][1] = 1;
    for(int i = 1;i < n;i++)
    {
        for(int x = 0;x <= max_x;x++)
        {
            for(int y = 0;y <= 1;y++)
            {
                dp[i+1][x][y] = (dp[i+1][x][y] + 1LL*dp[i][x][y] * (cnt(x, y) - i)) % MOD; // 1LL! wtf!
                if(x) dp[i+1][x-1][y] = (dp[i+1][x-1][y] + 1LL*dp[i][x][y] * (cnt(x-1, y) - cnt(x, y))) % MOD;
                if(y) dp[i+1][x][y-1] = (dp[i+1][x][y-1] + 1LL*dp[i][x][y] * (cnt(x, y-1) - cnt(x, y))) % MOD;
            }
        }
    }
    printf("%d", dp[n][0][0]);
    return 0;
}
