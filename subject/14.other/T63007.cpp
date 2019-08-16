#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int k, c, ans = 0;
    scanf("%d%d", &k, &c);
    while(k != 1)
    {
        int d = ((k-1) / (c+1)) + 1; // d for delta -- the step of each jump
        int border = (d-1)*(c+1);
        int jumps = (k-border-1) / d + 1;
        if(d == 1) jumps = k - 1;
        k -= jumps*d;
        ans += jumps;
    }
    printf("%d", ans);
    // for(int k0 = 2;k0 <= 1000;k0++)
    // {
    //     ans = 0;
    //     c = 2;
    //     k = k0;
    //     // scanf("%d%d", &k, &c);
    //     while(k != 1)
    //     {
    //         int d = ((k-1) / (c+1)) + 1; // d for delta
    //         int border = (d-1)*(c+1);
    //         int jumps = (k-border-1) / d + 1;
    //         if(d == 1) jumps = k - 1;
    //         k -= jumps*d;
    //         ans += jumps;
    //     }
    //     printf("%d: %d\n", k0, ans);
    //     // printf("%d", ans);
    // }
    return 0;
}
