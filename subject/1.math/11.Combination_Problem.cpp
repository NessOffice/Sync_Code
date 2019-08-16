#include <cstdio>
int dp[2010][2010], C[2010][2010];
int main()
{
    int t, k, n, m;
    scanf("%d%d", &t, &k);
    for(int i = 1;i < 2010;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1;j < i;j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % k;
    }
    for(int i = 0;i < 2010;i++)
        dp[i][0] = dp[0][i] = 0;
    for(int i = 1;i < 2010;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if(C[i][j] == 0) dp[i][j]++;
        }
        dp[i][i+1] = dp[i][i];
    }
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(m > n) m = n;
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
