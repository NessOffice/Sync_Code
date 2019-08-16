#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", a + i);
    sort(a, a + n);
    if(a[n-3] + a[n-2] <= a[n-1])
        printf("NO");
    else
    {
        printf("YES\n%d %d ", a[n-2], a[n-1]);
        for(int i = n-3;i >= 0;i--)
            printf("%d ", a[i]);
    }
    return 0;
}
