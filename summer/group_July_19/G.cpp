#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 20;
char str[maxn<<1];
int main()
{
    int n, len, ans = maxn;
    scanf("%d", &n);
    scanf("%s", str);
    len = strlen(str);
    for(int i = len;i < 2*len + 5;i++)
        str[i] = str[i-len];
    int x = 0, y = 0, z = 0;
    int c1 = 0, a1 = 0, b1 = 0;
    int c2 = 0, a2 = 0, b2 = 0;
    int c3 = 0, a3 = 0, b3 = 0;
    for(int i = 0;i < len;i++)
    {
        if(str[i] == 'A') x++;
        if(str[i] == 'B') y++;
        if(str[i] == 'C') z++;
    }
    for(int i = 0;i < z;i++)
    {
        if(str[i] == 'A') a1++;
        if(str[i] == 'B') b1++;
        if(str[i] == 'C') c1++;
    }
    for(int i = z;i < z + x;i++)
    {
        if(str[i] == 'A') a2++;
        if(str[i] == 'B') b2++;
        if(str[i] == 'C') c2++;
    }
    for(int i = z;i < z + y;i++)
    {
        if(str[i] == 'A') a3++;
        if(str[i] == 'B') b3++;
        if(str[i] == 'C') c3++;
    }
    for(int i = 0;i <= len;i++)
    {
        ans = min(ans, (z-c1)+(x-a2)+(b1+b2));
        ans = min(ans, (z-c1)+(y-b3)+(a1+a3));
        if(str[i] == 'A') a1--;
        if(str[i] == 'B') b1--;
        if(str[i] == 'C') c1--;
        if(str[i+z] == 'A'){a1++;a2--;a3--;}
        if(str[i+z] == 'B'){b1++;b2--;b3--;}
        if(str[i+z] == 'C'){c1++;c2--;c3--;}
        if(str[i+z+x] == 'A') a2++;
        if(str[i+z+x] == 'B') b2++;
        if(str[i+z+x] == 'C') c2++;
        if(str[i+z+y] == 'A') a3++;
        if(str[i+z+y] == 'B') b3++;
        if(str[i+z+y] == 'C') c3++;
    }
    printf("%d", ans);
    return 0;
}
/*
5
ABABC

12
ABCABCABCABC

4
ACBA

6
BABABA

9
ABABCBCAC
*/