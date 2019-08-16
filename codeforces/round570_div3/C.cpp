#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e5 + 5;
int main()
{
    LL q;
    scanf("%lld", &q);
    while(q--)
    {
        LL k, n, a, b;
        scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
        if(k <= n*b){printf("-1\n");continue;}
        k -= n*b; // caution: overflow if int
        printf("%lld\n", min(n, (k-1)/(a-b)));
    }
    return 0;
}
