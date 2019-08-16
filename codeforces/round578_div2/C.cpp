#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
LL gcd(LL a, LL b)
{
    if(a < b) return gcd(b, a);
    while(b)
    {
        swap(a, b);
        b = b % a;
    }
    return a;
}
int main()
{
    LL n, m, q, d;
    scanf("%lld%lld%lld", &n, &m, &q);
    d = gcd(n, m);
    LL sec_n = n / d;
    LL sec_m = m / d;
    while(q--)
    {
        LL sx, sy, ex, ey, begin_1, begin_2;
        scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
        if(sx == 1LL)
        {
            begin_1 = (sy-1LL) / sec_n * sec_n + 1LL;
            begin_2 = (begin_1-1LL) / sec_n * sec_m + 1LL;
        }
        else
        {
            begin_2 = (sy-1LL) / sec_m * sec_m + 1LL;
            begin_1 = (begin_2-1LL) / sec_m * sec_n + 1LL;
        }
        bool yes = true;
        if(ex == 1LL && (ey < begin_1 || ey >= begin_1+sec_n)) yes = false;
        if(ex == 2LL && (ey < begin_2 || ey >= begin_2+sec_m)) yes = false;
        printf("%s\n", yes ? "YES" : "NO");
    }
    return 0;
}
/*
4 6 5
1 1 2 3
2 6 1 2
2 6 2 4
2 1 2 4
2 1 2 3
*/