#include <cstdio>
#include <algorithm>
typedef long long LL;
const LL maxn = 5e4 + 5;
LL sum[maxn];
LL a[maxn], n, m;
int main()
{
    sum[0] = 0;
    for(LL i = 1;i < maxn;i++)
        sum[i] = sum[i-1] + i,
        a[i] = i;
    scanf("%lld%lld", &n, &m);
    LL head = 1, tail = n, len = n;
    while(len--)
    {
        if(len > 0 && m <= sum[len-1])
            a[head++] = n-len;
        else
            a[tail--] = n-len,
            m -= len;
    }
    for(LL i = 1;i <= n;i++)
        printf("%lld ", a[i]);
}
