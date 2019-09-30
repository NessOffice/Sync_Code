#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long LL;
LL omega2;
struct cp{LL real, imag;};
cp mul_cp(cp a, cp b, LL p)
{
    cp ans;
    ans.real = ((a.real*b.real%p + a.imag*b.imag%p*omega2%p) % p + p) % p;
    ans.imag = ((a.real*b.imag%p + a.imag*b.real%p) % p + p) % p;
    return ans;
}
LL qpow_cp(cp base, LL expo, LL p)
{
    cp ans = {1, 0};
    while(expo)
    {
        if(expo & 1LL)
            ans = mul_cp(ans, base, p);
        expo >>= 1LL;
        base = mul_cp(base, base, p);
    }
    return ans.real;
}
LL qpow_real(LL base, LL expo, LL p)
{
    LL ans = 1;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * base % p;
        expo >>= 1LL;
        base = base * base % p;
    }
    return ans;
}
LL cipolla(LL n, LL p)
{
    if(n == 0) return 0;
    if(qpow_real(n, (p-1)/2, p) != 1) return -1;
    LL a;
    while(1)
    {
        a = rand() % p;
        omega2 = ((a*a-n) % p + p ) % p;
        if(qpow_real(omega2, (p-1)/2, p) == p-1) break;
    }
    return qpow_cp((cp){a, 1}, (p+1)/2, p);
}
int main()
{
    srand(time(0));
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, p, ans1, ans2;
        scanf("%lld%lld", &n, &p);
        ans1 = cipolla(n, p), ans2 = p - ans1;
        if(ans1 == -1)
            printf("Hola!\n");
        else
        {
            if(ans1 > ans2) swap(ans1, ans2);
            if(ans2 != ans1 && ans2 != p)
                printf("%lld %lld\n", ans1, ans2);
            else
                printf("%lld\n", ans1);
        }
    }
    return 0;
}
/*
5000
254333177 1000000009
615398960 998244353
5025393 19491001
16761599 19491001
644876454 1000000009
38603383 998244353
10236560 19260817
9797307 19491001
2891367 19260817
63038360 998244353
27484912 1000000009
657941730 1000000009
16352262 19491001
454101824 1000000007
144567960 998244353
10382846 19260817
19121337 19491001
299808352 998244353
*/