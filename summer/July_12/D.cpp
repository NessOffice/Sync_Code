#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL n, ans = 0;
    scanf("%lld", &n);
    LL upper = LL(pow(n, 0.5));
    for(LL x = 1, y;;x = (LL(pow(n-y*y, 0.5)) + 1))
    {
        y = (LL(pow(n-x*x, 0.5)));
        if(x*x + y*y == n) ans++;
        if(x >= y) break;
    }
    printf("%lld\n", ans);
    return 0;
}
// 16: 10000000000000000
// 15: 9000000000000000