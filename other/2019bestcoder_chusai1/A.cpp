#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 5;
int a[maxn], b[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        for(int i = 0;i < n;i++)
            scanf("%d", &b[i]);
        for(int i = n-1;i >= 0;i--)
        {
            if(a[i] == 0 && b[i] == 0) continue;
            if(a[i] && b[i])
            {
                int d = __gcd(a[i], b[i]);
                printf("%d/%d\n", a[i]/d, b[i]/d);
                break;
            }
            if(a[i])
                printf("1/0\n");
            if(b[i])
                printf("0/1\n");
            break;
        }
    }
    return 0;
}
