#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 505;
int a[maxn], b[maxn], dp[2][maxn], ptr[2][maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++) scanf("%d", a+i);
    for(int i = 0;i < m;i++) scanf("%d", b+i);
    for(int i = 0;i < n;i++)
    {
        for(int i2 = 0;i2 < i;i2++)
        {
            int flag = (a[i] > a[i2] ? 1 : 0);
            for(int j = ptr[flag][i2];j < m;j++)
            {
                if(dp[flag][i2] + 1 > dp[flag][i])
            }
        }
    }
    return 0;
}