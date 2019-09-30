#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
int main()
{
    LL b, g, n, ans;
    scanf("%lld%lld%lld", &b, &g, &n);
    ans = n+1;
    if(n >= b) ans -= (n-b);
    if(n >= g) ans -= (n-g);
    printf("%lld", ans);
    return 0;
}