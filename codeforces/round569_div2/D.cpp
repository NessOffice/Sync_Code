#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n/2;i++)
        for(int j = 1;j <= m;j++)
            printf("%d %d\n%d %d\n", i, j, n+1-i, m+1-j);
    if(n & 1)
    {
        for(int j = 1;j <= m/2;j++)
            printf("%d %d\n%d %d\n", n/2+1, j, n/2+1, m+1-j);
        if(m & 1)
            printf("%d %d\n", n/2+1, m/2+1);
    }
    return 0;
}
