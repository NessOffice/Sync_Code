#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int x, y, z, ans = 0;
    scanf("%d%d%d", &x, &y, &z);
    ans = x - y;
    if((ans-z)*(ans+z) <= 0 && z)
        putchar('?');
    else
    {
        if(ans > 0) putchar('+');
        if(ans == 0) putchar('0');
        if(ans < 0) putchar('-');
    }
    return 0;
}