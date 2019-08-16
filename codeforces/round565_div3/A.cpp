#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    long long q, num;
    scanf("%lld", &q);
    while(q--)
    {
        long long ans = 0;
        scanf("%lld", &num);
        while(num % 5 == 0)
        {
            num /= 5;
            ans += 3;
        }
        while(num % 3 == 0)
        {
            num /= 3;
            ans += 2;
        }
        while(num % 2 == 0)
        {
            num /= 2;
            ans++;
        }
       printf("%lld\n", (num == 1 ? ans : -1));
    }
    return 0;
}