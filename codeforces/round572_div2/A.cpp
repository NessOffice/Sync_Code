#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
int main()
{
    char s[200];
    int n;
    scanf("%d%s", &n, s);
    int one = 0, zero = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '1')
            one++;
        else
            zero++;
    }
    if(one != zero)
        printf("1\n%s", s);
    else
        printf("2\n%c %s", s[0], s+1);
    return 0;
}
