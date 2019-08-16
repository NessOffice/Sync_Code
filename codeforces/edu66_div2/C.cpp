#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const LL maxn = 2e5 + 5;
LL a[maxn];
using namespace std;
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL n, k;
        scanf("%lld%lld", &n, &k);
        LL minv = k+1;
        for(LL i = 1;i <= n;i++)
        {
            scanf("%lld", &a[i]);
            if(i > minv && (a[i] - a[i-k] < a[minv] - a[minv-k]))
                minv = i;
        }
        printf("%lld\n", (a[minv] + a[minv-k]) / 2);
    }
    return 0;
}