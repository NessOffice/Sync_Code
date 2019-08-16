#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL qpow(LL base, LL expo)
{
    LL ans = 1LL;
    while(expo)
    {
        if(expo & 1)
            ans = ans * base % MOD;
        expo >>= 1;
        base = base * base % MOD;
    }
    return ans;
}
LL solve(LL m, LL n)
{
    if(n == 0)
        return (m == 0 ? 1 : solve(m-1, 1));
    switch(m)
    {
        case 0: return n + 1;
        case 1: return n + 2;
        case 2: return 2*n + 3;
        case 3: return qpow(2, n + 3) - 3;
        case 4: return qpow(2, solve(m, n-1) + 3) - 3;
    }
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while (T--)
    {
        LL n, m;
        scanf("%lld%lld", &m, &n);
        printf("%lld\n", solve(m, n));
    }
    return 0;
}