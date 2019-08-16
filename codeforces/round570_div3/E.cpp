#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxp = 26;
int dp[maxn][maxp]; // dp[length][tail]
int ch2int(char ch){return ch - 'a';}
int main()
{
    memset(dp, 0, sizeof(dp));
    int n, k, ans = 0;
    char s[maxn];
    scanf("%d%d", &n, &k);
    scanf("%s", s+1);
    for(int i = 1;i <= n;i++)
    {
        int ch_tail = ch2int(s[i]);
        for(int len = i-1;len >= 1;len--)
        {
            dp[len+1][ch_tail] = 0;
            for(int ch = 0;ch < maxp;ch++)
                dp[len+1][ch_tail] += dp[len][ch];
        }
        dp[1][ch_tail] = 1;
    }
    for(int len = n;len >= 1 && k;len--)
        for(int ch = 0;ch < maxp && k;ch++)
        {
            int num = dp[len][ch];
            if(num > k) num = k;
            k -= num;
            ans += (num * (n-len));
        }
    if(k > 1) ans = -1;
    if(k == 1) ans += n; // deal with ""
    printf("%d\n", ans);
    return 0;
}
