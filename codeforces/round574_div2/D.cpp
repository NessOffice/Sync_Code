#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const LL MOD = 998244353;
LL digit[20], len;
LL fun(LL num)
{
    len = 0;
    while(num)
    {
        digit[++len] = num % 10;
        num /= 10;
    }
    LL ans = 0;
    while(len > 0)
    {
        ans *= 100LL;
        ans += (11*digit[len--]);
        ans %= MOD;
    }
    return ans;
}
int main()
{
    LL n, res = 0;
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++)
    {
        LL temp;
        scanf("%lld", &temp);
        res = (res + n*fun(temp)) % MOD;
    }
    printf("%lld", res);
    return 0;
}
