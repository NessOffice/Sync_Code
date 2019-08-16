#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
int main()
{
    LL T, n, s, t;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld%lld", &n, &s, &t);
        LL num1 = n-s, num2 = n-t;
        LL ans = max(num1+1, num2+1);
        printf("%lld\n", ans);
    }
    return 0;
}