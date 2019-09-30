#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e6+5;
int main()
{
    LL k;
    while(1)
    {
        scanf("%lld", &k);
        if(k == 0) break;
        LL ans = k % 6;
        k = (k - ans) / 6;
        if(ans == 0) ans = 6;
        if(ans <= 2)
        {
            bool ok = false;
            LL x = 1, y;
            y = sqrt(2*k);
            if(y*(y+1)<=2*k) y++;
            if(ans == 1 || k == 0){
                if(y*(y-1)==2*k) ok = true;
            }else{
                while(x < y)
                {
                    y = sqrt(2*k-x*(x-1));
                    if(y*(y+1)<=2*k-x*(x-1)) y++;
                    if(y*(y-1)==2*k-x*(x-1)){ok = true;break;}
                    x = sqrt(2*k-y*(y-1));
                    if(x*(x+1)<=2*k-y*(y-1)) x++;
                    if(x*(x-1)==2*k-y*(y-1)){ok = true;break;}
                    x++;
                }
                if(x*(x+1)+y*(y+1)==2*k) ok = true;
            }
            if(!ok) ans += 6;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*


1
2
7
8
13
14
19
20
25
26
31
32
37
38
43
44

*/