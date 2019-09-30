#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 998244353LL;
LL calc_sum(LL a, LL b, LL c, LL n)
{
    if(n == 0) return b / c;
    LL ans = (n + 1) * (b / c) % MOD;
    ans += ((n * (n + 1) / 2) * (a / c) % MOD);
    ans %= MOD;
    a %= c, b %= c;
    if((a * n + b) / c < 1) return ans;
    LL m = (a * n + b) / c;
    ans += (n * m % MOD);
    ans %= MOD;
    ans -= calc_sum(c, c-b-1, a, m-1);
    ans = ((ans % MOD) + MOD) % MOD;
    return ans;
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, a, b, c;
        scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
        printf("%lld \n", calc_sum(a, b, c, n));
    }
    return 0;
}
/*
2
4 3 9 6
2 1 0 2
*/