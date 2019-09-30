#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3+5;
const int MOD = 1e9 + 7;
int a[maxn][maxn], sum_row[maxn], sum_col[maxn];
char a_str[maxn];
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s", a_str);
        for(int j = 0;j < n;j++)
        {
            a[i][j] = a_str[j] - '0';
            sum_row[i] ^= a[i][j],
            sum_col[j] ^= a[i][j];
        }
    }
    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
        ans += (sum_row[i]^sum_col[j]^a[i][j]);
    printf("%d", min(ans, n*n-ans));
    return 0;
}
