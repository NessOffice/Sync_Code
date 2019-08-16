#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n, maxv = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i] >= 0) a[i] = -a[i]-1;
        if(a[i] < a[maxv]) maxv = i;
    }
    if(n & 1) a[maxv] = -a[maxv]-1;
    for(int i = 0;i < n;i++)
        printf("%d ", a[i]);
    return 0;
}
