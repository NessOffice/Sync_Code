#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
    int n, n_odd, n_even, a[maxn];
    n_odd = n_even = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i] & 1)
            n_odd++;
        else
            n_even++;
    }
    if(n_odd != n && n_even != n)
        sort(a, a+n);
    for(int i = 0;i < n;i++)
    {
        if(i) putchar(' ');
        printf("%d", a[i]);
    }
    return 0;
}