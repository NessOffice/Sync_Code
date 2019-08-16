#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 105;
const LL maxp = 26;
LL dp[maxn][maxp]; // dp[length][tail]
LL ch2ll(char ch){return (LL)(ch - 'a');}
int main()
{
    memset(dp, 0LL, sizeof(dp));
    LL n, k, ans = 0;
    char s[maxn];
    scanf("%lld%lld", &n, &k);
    scanf("%s", s+1);
    for(LL i = 1;i <= n;i++)
    {
        LL ch_tail = ch2ll(s[i]);
        for(LL len = i-1;len >= 1;len--)
        {
            dp[len+1][ch_tail] = 0;
            for(LL ch = 0;ch < maxp;ch++)
                dp[len+1][ch_tail] += dp[len][ch];
        }
        dp[1][ch_tail] = 1;
    }
    for(LL len = n;len >= 1 && k;len--)
        for(LL ch = 0;ch < maxp && k;ch++)
        {
            LL num = dp[len][ch];
            if(num > k) num = k;
            k -= num;
            ans += (num * (n-len));
        }
    if(k > 1) ans = -1;
    if(k == 1LL) ans += n; // deal with ""
    printf("%lld\n", ans);
    return 0;
}
