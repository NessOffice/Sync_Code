#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, a[3000];
    scanf("%d", &n);
    for(int i = 0;i < 2*n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+2*n);
    if(a[0] == a[2*n-1]) printf("-1");
    else for(int i = 0;i < 2*n;i++)
    {
        if(i) putchar(' ');
        printf("%d", a[i]);
    }
    return 0;
}