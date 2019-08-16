#include <cstdio>
#include <cstring>
typedef long long LL;
int main()
{
    LL n, ans, cnt;
    while(~scanf("%lld", &n))
    {
        ans = 0;
        for(LL a = 1;a*a*a <= n;a++)
        {
            LL temp = n/a;//twice faster
            for(LL b = a;a*b*b <= n;b++)
            {
                if(a == b) cnt = 1+3*((temp/b)-b);
                else cnt = 3+6*((temp/b)-b);
                ans += cnt;
            }
        }
        printf("%lld\n", ans);
    }
}
