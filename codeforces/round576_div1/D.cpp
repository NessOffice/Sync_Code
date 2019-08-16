#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 55;
int dp[maxn][maxn][maxn][maxn];
int f(int x1, int y1, int x2, int y2)
{
    int& dp_now = dp[x1][y1][x2][y2];
    if(dp_now != -1) return dp_now;
    dp_now = max(x2-x1+1, y2-y1+1);
    for(int x = x1;x < x2;x++)
        dp_now = min(dp_now, f(x1, y1, x, y2) + f(x+1, y1, x2, y2));
    for(int y = y1;y < y2;y++)
        dp_now = min(dp_now, f(x1, y1, x2, y) + f(x1, y+1, x2, y2));
    return dp_now;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    char grid;
    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
        scanf(" %c", &grid),
        dp[i][j][i][j] = (grid == '#');
    printf("%d", f(1, 1, n, n));
    return 0;
}
