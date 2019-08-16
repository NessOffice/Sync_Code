#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL a, b, c, d, ans = 0;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    if(c - b < d) ans += (d - (c - b));
    if(b - a < d) ans += (d - (b - a));
    printf("%lld", ans);
    return 0;
}
