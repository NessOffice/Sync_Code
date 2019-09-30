#include <cstdio>
#include <cstring>
typedef long long LL;
const LL MOD = 998244353LL;
LL sum2(LL num){return num * (num+1) % MOD * (2*num+1) % MOD * 166374059LL % MOD;} // 166374059: inv of 6
LL sum(LL num){return (num*(num+1)/2) % MOD;}
LL qpow(LL base, LL expo)
{
    LL ans = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans;
}
int main()
{
    LL n;
    scanf("%lld", &n);
    LL ans = 0;
    for(LL l = 1LL, r;l <= n;l = r + 1LL)
    {
        r = n/(n/l);
        ans = (ans + (n/l) * (2*(sum2(r)-sum2(l-1)) + 3*(sum(r)-sum(l-1)) + 5*(r-l+1)) % MOD + MOD) % MOD;
    }
    printf("%lld", ans);
    return 0;
}
