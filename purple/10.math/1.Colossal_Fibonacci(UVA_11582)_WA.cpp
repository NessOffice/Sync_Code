#include <cstdio>
#include <map>
using namespace std;
typedef unsigned long long LL;
const LL maxn = 1e7 + 7;
map<pair<LL, LL>, LL> records;
LL T, a, b, n, p, f[maxn];
LL qpow(LL base,LL expo, LL MOD)
{
	base %= MOD;
    LL ans = 1;
    while(expo)
    {
        if(expo & 1)
            ans = ans * base % MOD;
        expo >>= 1;
        base = base * base % MOD;
    }
    return ans % MOD;
}
int main()
{
    scanf("%lld", &T);
    while(T--)
    {
        records.clear();
        scanf("%lld%lld%lld", &a, &b, &n);
        f[0] = 0;f[1] = 1%n;//if n == 1
        for(p = 1;p == 1 || !(f[p-1] == 0 && f[p] == 1);p++)
        {
            records[make_pair(f[p-1], f[p])] = 1;
            f[p+1] = (f[p-1] + f[p]) % n;
        }
        printf("%lld\n", f[qpow(a, b, p-1)]);
    }
}
