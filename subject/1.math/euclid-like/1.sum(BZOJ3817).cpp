#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL T, n, r;
double sqrt_r;
LL calc_sum(LL a, LL b, LL c, LL n) // \sum ((a \sqrt r + b) / c * d)
{
    if(n == 0) return 0;
    LL gcd = __gcd(a, __gcd(b, c));a /= gcd, b /= gcd, c /= gcd;
    LL k = (a * sqrt_r + b) / c;
    if(k) return k*n*(n+1)/2 + calc_sum(a, b-c*k, c, n);
    LL m = (a * sqrt_r + b) / c * n;
    return n*m - calc_sum(a*c, -b*c, a*a*r-b*b, m);
}
int main()
{
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld", &n, &r);
        sqrt_r = sqrt(r);
        int int_sqrt_r = sqrt_r;
        if(int_sqrt_r * int_sqrt_r == r){
            if(int_sqrt_r & 1) printf("%lld\n", n-2*((n+1)/2));
            else printf("%lld\n", n);
        }else
            printf("%lld\n", n + 4*calc_sum(1, 0, 2, n) - 2*calc_sum(1, 0, 1, n));
    }
    return 0;
}
