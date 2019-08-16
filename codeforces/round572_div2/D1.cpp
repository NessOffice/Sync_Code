#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int deg[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++, deg[v]++;
    }
    bool ok = true;
    for(int u = 1;u <= n;u++)
        if(deg[u] == 2)
            ok = false;
    printf("%s", ok ? "YES" : "NO");
    return 0;
}
