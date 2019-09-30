#include <cstdio>
#include <cstring>
typedef long long LL;
const LL maxn = 9; // nine primes to ensure the algorithm
LL n, primes[maxn] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
LL qadd(LL x, LL y, LL mod) {
    x %= mod;
    y %= mod;
    LL c = (long double)x / mod * y;
    LL d = x * y - c * mod;
    return ((d % mod) + mod) % mod;
}
LL qmul(LL a, LL b, LL MOD)
{
    LL ans = 0LL;
    while(b)
    {
        if(a & 1LL)
            ans = qadd(ans, a, MOD);
        b >>= 1LL;
        a = qadd(a, a, MOD);
    }
    return ans;
}
LL qpow(LL base, LL expo, LL MOD)
{
    LL ans = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            ans = qmul(ans, base, MOD) % MOD;
        expo >>= 1LL;
        base = qmul(base, base, MOD) % MOD;
    }
    return ans;
}
bool miller_rabin(LL num)
{
    if(num == 1LL) return false;
    for(LL i = 0;i < maxn;i++)
    {
        if(num == primes[i]) return true;
        if(num < primes[i]) return false;
        LL expo = num-1LL, res;
        res = qpow(primes[i], expo, num);
        if(res != 1LL) return false;
        while(res == 1LL && !(expo & 1LL))
        {
            expo /= 2LL;
            res = qpow(primes[i], expo, num);
            if(res != 1LL && res != num-1LL) return false;
        }
    }
    return true;
}
int main()
{
    while(~scanf("%lld", &n))
        printf("%c\n", miller_rabin(n) ? 'Y' : 'N');
    return 0;
}
