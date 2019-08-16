#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n, x, ans = 1;
    scanf("%d%d", &n, &x);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 1;i < n;i++)
        if(a[i] + a[i-1] <= x)
            ans = i + 1;
    printf("%d", ans);
    return 0;
}
/*
5 10
4 8 1 9 7
*/