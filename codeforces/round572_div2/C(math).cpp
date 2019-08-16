#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int sum[maxn];
int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", sum + i);
        sum[i] += sum[i-1];
    }
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", (sum[r] - sum[l-1]) / 10);
    }
    return 0;
}
