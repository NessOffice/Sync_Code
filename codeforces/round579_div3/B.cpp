#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[500];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        n *= 4;
        for(int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        bool ok = true;
        int lft = 0, rgt = n-1;
        if(a[lft]!=a[lft+1]) ok = false;
        if(a[rgt]!=a[rgt-1]) ok = false;
        int base = a[lft]*a[rgt];
        while(ok && lft < rgt)
        {
            if(a[lft]!=a[lft+1]) ok = false;
            if(a[rgt]!=a[rgt-1]) ok = false;
            if(base != a[lft]*a[rgt]) ok = false;
            lft += 2, rgt -= 2;
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
