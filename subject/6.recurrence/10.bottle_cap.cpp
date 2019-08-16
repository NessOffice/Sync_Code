#include <cstdio>
#include <algorithm>
typedef long long LL;
const LL maxn = 1e5 + 7;
LL pos[maxn];
int main()
{
    LL A, B;
    LL maxv = 0;
    scanf("%lld%lld", &A, &B);
    for(LL i = 0;i < A;i++)
    {
        scanf("%lld", &pos[i]);
        maxv = std::max(maxv, pos[i]);
    }
    std::sort(pos, pos + A);
    LL l = 0, r = maxv;
    while(r > l)
    {
        LL m = (l+r+1)/2, ok = 1;//caution m
        LL i = 0, j = 0, cnt = B-1;
        while(cnt-- && ok)
        {
            while(j < A && pos[j] < pos[i] + m) j++;
            if(j == A) ok = 0;
            i = j;
        }
        if(ok) l = m;
        else r = m-1;
    }
    printf("%lld", l);
}
