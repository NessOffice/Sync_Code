#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, x, ans;
        scanf("%lld%lld", &n, &x);
        if(2*x <= n) ans = 2*x;
        else ans = n;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
5
3 1
4 2
69 6
3 2
5 4
*/