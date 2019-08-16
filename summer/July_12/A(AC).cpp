#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e5 + 5;
LL val[maxn];
int main()
{
    LL n, k, p;
    scanf("%lld%lld%lld", &n, &p, &k);
    for(LL i = 0;i < n;i++)
    {
        scanf("%lld", val + i);
        val[i] = ((val[i]*val[i]%p*val[i]%p*val[i]%p - k*val[i]%p)+p)%p;
    }
    sort(val, val+n);
    LL last = 0, ans = 0;
    for(LL i = 0;i < n;i++)
    {
        if(i && val[i] == val[i-1]) continue;
        while(last < i) last = i;
        while(last < n && val[last] == val[i]) last++;
        LL num = last - i;
        ans += (num*(num-1)/2%p);
        ans %= p;
    }
    printf("%lld", ans);
    return 0;
}
