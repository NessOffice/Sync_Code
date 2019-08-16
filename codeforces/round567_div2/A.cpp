#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    LL num = (x + y) / z;
    LL num2 = x / z + y / z;
    x %= z;
    y %= z;
    LL d = 0LL;
    if(num2 < num)
    {
        d = min(x, z - x);
        d = min(d, y);
        d = min(d, z - y);
    }
    printf("%lld %lld", num, d);
    return 0;
}
