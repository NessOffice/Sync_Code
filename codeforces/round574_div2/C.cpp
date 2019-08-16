#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL h[2][maxn], dp[2][maxn];
int main()
{
    LL n;
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++) scanf("%lld", &h[0][i]);
    for(LL i = 0;i < n;i++) scanf("%lld", &h[1][i]);
    dp[0][0] = h[0][0], dp[1][0] = h[1][0];
    if(n > 1) dp[0][1] = h[0][1] + h[1][0], dp[1][1] = h[0][0] + h[1][1];
    for(LL i = 2;i < n;i++)
    {
        dp[0][i] = h[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = h[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }
    printf("%lld", max(dp[0][n-1], dp[1][n-1]));
    return 0;
}
