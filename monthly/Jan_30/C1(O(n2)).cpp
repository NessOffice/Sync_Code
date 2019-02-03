#include <cstdio>
typedef long long ll;
int main()
{
    ll n, ans, e, a, ans2;
    while(scanf("%lld", &n) && n)
    {
        ans2 = 0;
        for(ll i = 1;i <= n;i++)
        {
            ans = 1, a = 2;
            ll temp = i;
            while(temp > 1)
            {
                e = 1;
                while(temp % a == 0)
                {
                    temp /= a;
                    e++;
                }
                a++;
                ans *= e;
            }
            ans2 += ans*(n/i);
        }
        printf("%lld\n", ans2);
    }
}