#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e2 + 5;
const int INF = (1<<30);
int ai, q, n, k, l, r;
int main()
{
    scanf("%d", &q);
    while(q--)
    {
        l = INF, r = 0;
        scanf("%d%d", &n, &k);
        for(int i = 0;i < n;i++)
        {
            scanf("%d", &ai);
            l = min(l, ai+k);
            r = max(r, ai-k);
        }
        printf("%d\n", (l < r ? -1 : l));
    }
    return 0;
}
