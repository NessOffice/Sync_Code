#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
LL gcd(LL a, LL b)
{
    if(a < b) return gcd(b, a);
    while(b)
    {
        swap(a, b);
        b = b % a;
    }
    return a;
}
int main()
{
    LL n, lst, now;
    scanf("%lld", &n);
    scanf("%lld", &lst);
    for(LL i = 1;i < n;i++)
    {
        scanf("%lld", &now);
        lst = gcd(lst, now);
    }
    LL ans = 1;
    for(LL i = 2;i*i <= lst;i++)
    {
        LL expo = 0;
        while(lst % i == 0)
        {
            lst /= i;
            expo++;
        }
        ans *= (expo + 1);
    }
    if(lst != 1LL)
        ans *= 2LL;
    printf("%lld", ans);
    return 0;
}
/*
4 6 5
1 1 2 3
2 6 1 2
2 6 2 4
2 1 2 4
2 1 2 3
*/