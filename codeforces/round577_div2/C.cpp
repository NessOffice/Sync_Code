#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
LL a[maxn];
int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    for(LL i = 1;i <= n;i++)
        scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    LL mid = (n+1) / 2, r = mid+1;
    while(k)
    {
        while(r <= n && a[r] == a[mid]) r++;
        if(r > n)
        {
            a[mid] += k / (r - mid);
            k = 0;
        }
        else if((r-mid)*(a[r]-a[mid]) >= k)
        {
            a[mid] += k / (r-mid);
            k = 0;
        }
        else
        {
            k -= ((a[r]-a[mid])*(r-mid));
            a[mid] = a[r];
        }
    }
    printf("%lld", a[mid]);
    return 0;
}
/*
7 7
4 1 2 4 3 4 4

7 8
4 1 2 4 3 4 4

*/