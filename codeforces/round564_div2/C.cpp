#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int dep[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        int temp;
        scanf("%d", &temp);
        dep[temp] = 0;
    }
    for(int i = 1;i <= n;i++)
    {
        int temp;
        scanf("%d", &temp);
        dep[temp] = i;
    }
    int ans = 0, ok = 0;
    if(dep[1])
    {
        int k, j; // 1, 2, ..., k, they're continous
        for(k = 2;dep[k] == dep[1] + k-1;k++); // a candy
        if(dep[k-1] == n)
        {
            for(j = k;j <= n && dep[j] <= j - k;j++);
            if(j == n+1)
                ans = n - k + 1,
                ok = 1;
        }
    }
    if(!ok)
        for(int i = 1;i <= n;i++)
            ans = max(ans, n + dep[i] - i + 1);
    printf("%d", ans);
    return 0;
}