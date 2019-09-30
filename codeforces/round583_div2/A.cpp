#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL n, e, d;
    scanf("%lld%lld%lld", &n, &e, &d);
    d *= 5;
    LL ans = n;
    for(LL i = 0;i < d;i++)
    {
        if(n < i*e) break;
        ans = min(ans, (n-i*e)%d);
    }
    printf("%lld", ans);
    return 0;
}