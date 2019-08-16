#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1.5e5+5;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = n-1;i >= 0;i--)
    {
        if(i == n-1 || (a[i]+1 != a[i+1] && a[i] != a[i+1])){a[i]++;continue;}
        if(i == 0 && a[i] != 1){a[i]--;continue;}
        if(i == 0 || a[i] == a[i-1]) continue;
        if(i != 0 && a[i] != 1 && a[i]-1 != a[i-1]){a[i]--;continue;}
    }
    printf("%d", unique(a, a + n) - a);
    return 0;
}
