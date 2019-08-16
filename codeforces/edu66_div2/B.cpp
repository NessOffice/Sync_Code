#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 1e5 + 5;
const LL upper = (1LL<<32)-1;
using namespace std;
LL loop[maxn], len = 0;
int main()
{
    LL l, x = 0, looping = 1, over_flag = 0, over_depth = maxn;
    LL num_v;
    char cmd[30], num[30];
    scanf("%lld", &l);
    while(l--)
    {
        scanf("%s", cmd);
        if(over_flag)
        {
            if(cmd[0] == 'f')
                scanf("%s", num);
            continue;
        }
        if(cmd[0] == 'f')
        {
            scanf("%s", num);
            sscanf(num, "%lld", &num_v);
            if(over_depth > len && 1LL*looping * num_v > upper)
                over_depth = len;
            else if(over_depth > len)
                looping *= num_v;
            loop[len++] = num_v;
        }
        if(cmd[0] == 'a')
        {
            if(len > over_depth)
                over_flag = 1;
            else
                x += looping;
            if(x > upper)
                over_flag = 1;
        }
        if(cmd[0] == 'e')
        {
            len--;
            if(len < over_depth)
                looping /= loop[len];
            if(len == over_depth)
                over_depth = maxn;
        }
    }
    if(over_flag)
        printf("OVERFLOW!!!");
    else
        printf("%lld", x);
    return 0;
}