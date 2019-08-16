#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2005;
const int INF = 1e8;
int sum[maxn][maxn];
char grids[maxn];
int main()
{
    int n, k;
    for(int i = 1;i <= n;i++)
    {
        scanf("%s", grids+1);
        for(int j = 1;j <= n;j++)
            sum[i][j] = (grids[j] == 'B') + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }
    int ans1 = 0; // the white lines already exist
    for(int i = 1;i <= n;i++)
    {
        ans1 += (sum[i][n] - sum[i-1][n] == n);
        ans1 += (sum[n][i] - sum[n][i-1] == n);
    }
    int ans2 = 0; // the white lines created by the eraser
    
    printf("%d", ans1 + ans2);
    return 0;
}
