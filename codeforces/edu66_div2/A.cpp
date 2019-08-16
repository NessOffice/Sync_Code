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
        LL n, k, ans = 0;
        scanf("%lld%lld", &n, &k);
        while(n)
        {
            while(n && n % k == 0)
            {
                n /= k;
                ans++;
            }
            if(n % k)
            {
                ans += (n - n / k * k);
                n = n / k * k;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}