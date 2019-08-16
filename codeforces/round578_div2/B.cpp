#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m, k, lst, now, ok = 1;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d", &lst);
        for(int i = 1;i < n;i++)
        {
            scanf("%d", &now);
            if(ok == 0) continue;
            if(now > lst + m + k){ok = 0;continue;}
            m -= (max(0, now - k) - lst);
            lst = now;
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
