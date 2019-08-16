#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+9;
const LL maxn = 5e3+3;
LL a[maxn], dp[maxn], inv[maxn];
void calc_inv()
{
	inv[1] = 1;
	for(LL i = 2;i < maxn;i++)
		inv[i] = (MOD - MOD/i) * inv[MOD % i] % MOD;
}
int main()
{
    calc_inv();
    LL n;
    scanf("%lld", &n);
    for(LL i = 1;i <= n;i++) scanf("%lld", a + i);
    sort(a+1, a+n+1);
    dp[0] = 1;
    for(LL i = 1;i <= n;i++)
    {
        dp[i] = 1;
        LL dup = 1, lst = -1;
        for(LL j = 1;j <= i;j++)
        {
            if(a[j] == lst) dup++;
            else dup = 1;
            lst = a[j];
            dp[i] = dp[i] * j % MOD;
            dp[i] = dp[i] * inv[dup] % MOD;
        }
        LL fac = 1;
        dup = 1, lst = -1;
        dp[i] = ((dp[i] - dp[i-1]) % MOD + MOD) % MOD;
        for(LL j = i-1;j >= 1;j--)
        {
            if(a[j+1] == lst) dup++;
            else dup = 1;
            lst = a[j+1];
            fac = fac * (i-j) % MOD;
            fac = fac * inv[dup] % MOD;
            dp[i] = ((dp[i] - dp[j-1]*fac) % MOD + MOD) % MOD;
        }
    }
    printf("%lld", dp[n]);
    return 0;
}
/*
4
0 1 2 3

5
1 1 2 1 1

13
1 2 3 4 5 6 7 8 9 10 11 12 13
*/