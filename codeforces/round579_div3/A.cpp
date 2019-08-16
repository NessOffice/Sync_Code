#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[300];
int main()
{
    int q, n;
    scanf("%d", &q);
    while(q--)
    {
        int st;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d", &a[i]);
            if(a[i] == 1) st = i;
        }
        bool ok = false;
        int i, step;
        for(i = (st+1)%n, step = 2;i != st;i = (i+1)%n, step++)
            if(a[i] != step) break;
        if(i == st) ok = true;
        for(i = (st+n-1)%n, step = 2;i != st;i = (i+n-1)%n, step++)
            if(a[i] != step) break;
        if(i == st) ok = true;
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
/*
5
4
1 2 3 4
3
1 3 2
5
1 2 3 5 4
1
1
5
3 2 1 5 4

1
5
1 2 3 5 4
*/