#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 405;
const int MOD = 1e9 + 7;
struct Matrix
{
    int r, c, a[maxn][maxn];
    // Matrix(int r, int c):r(r), c(c){memset(a, 0, sizeof(a));}
    void swap_row(int i1, int i2){for(int j = 0;j < c;j++) swap(a[i1][j], a[i2][j]);}
    void mul_row(int i, int k){for(int j = 0;j < c;j++) a[i][j] = ((1LL*a[i][j]*k%MOD)+MOD)%MOD;}
    void mul_and_add(int i1, int i2, int k){for(int j = 0;j < c;j++) a[i2][j] = ((a[i2][j] + 1LL*a[i1][j]*k%MOD)%MOD+MOD)%MOD;}
    void print(){for(int i = 0;i < r;i++) for(int j = 0;j < c;j++) printf("%d%c", a[i][j], (j == c-1 ? '\n' : ' '));}
}A, A_inv;
int calc_inv(int num)
{
    int ans = 1, base = num, expo = MOD-2;
    while(expo)
    {
        if(expo & 1)
            ans = (1LL * ans * base) % MOD;
        expo >>= 1;
        base = 1LL * base * base % MOD;
    }
    return ans;
}
int n;
bool solve()
{
    for(int i = 0;i < n;i++)
    {
        if(A.a[i][i] == 0)
            for(int i2 = i+1;i2 < n;i2++)
                if(A.a[i2][i])
                {
                    A.swap_row(i, i2);
                    A_inv.swap_row(i, i2);
                    break;
                }
        if(A.a[i][i] == 0) return false;
        int inv_now = calc_inv(A.a[i][i]);
        A_inv.mul_row(i, inv_now);A.mul_row(i, inv_now);
        for(int i2 = i+1;i2 < n;i2++)
            {A_inv.mul_and_add(i, i2, -A.a[i2][i]);A.mul_and_add(i, i2, -A.a[i2][i]);}
    }
    for(int i = n-2;i >= 0;i--)
        for(int i2 = i+1;i2 < n;i2++)
        {
            A_inv.mul_and_add(i2, i, -A.a[i][i2]);
            A.mul_and_add(i2, i, -A.a[i][i2]);
        }
    A_inv.print();
    return true;
}
int main()
{
    scanf("%d", &n);
    A.r = A.c = A_inv.r = A_inv.c = n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            scanf("%d", &A.a[i][j]);
            A_inv.a[i][j] = (i == j ? 1 : 0);
        }
    if(solve() == false)
        printf("No Solution\n");
    return 0;
}
