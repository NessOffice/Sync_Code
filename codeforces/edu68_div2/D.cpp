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
        bool alice = true;
        LL n, k;
        scanf("%lld%lld", &n, &k);
        if((k % 3) && (n % 3 == 0)) alice = false;
        if(k % 3 == 0)
        {
            n %= (k+1);
            if((n % 3 == 0) && n != k) alice = false;
        }
        printf("%s\n", alice ? "Alice" : "Bob");
    }
    return 0;
}