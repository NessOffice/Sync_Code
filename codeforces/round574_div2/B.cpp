#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int main()
{
    LL n, k, x, step[3] = {1, -2};
    scanf("%lld%lld", &n, &k);
    x = (-3+(LL)(sqrt(9+8*(n+k))))/2;
    LL i = 0;
    while(x*x+3*x-2*(n+k) != 0)
    {
        x += step[i];
        i++;
    }
    printf("%lld", n-x);
    return 0;
}
