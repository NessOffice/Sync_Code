#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 55;
const LL MOD = 1e9 + 7;
struct Matrix
{
    LL r, c, a[maxn][maxn];
    Matrix(LL r, LL c):r(r), c(c){memset(a, 0, sizeof(a));}
    void clr(){memset(a, 0, sizeof(a));}
    void unitize(){clr();for(LL i = 0;i < r;i++) a[i][i] = 1;}
    void swap_row(LL i1, LL i2){for(LL j = 0;j < c;j++) swap(a[i1][j], a[i2][j]);}
    void mul_row(LL i, LL k){for(LL j = 0;j < c;j++) a[i][j] = ((1LL*a[i][j]*k%MOD)+MOD)%MOD;}
    void mul_and_add(LL i1, LL i2, LL k){for(LL j = 0;j < c;j++) a[i2][j] = ((a[i2][j] + 1LL*a[i1][j]*k%MOD)%MOD+MOD)%MOD;}
    // void print(){for(LL i = 0;i < r;i++) for(LL j = 0;j < c;j++) printf("%d%c", a[i][j], (j == c-1 ? '\n' : ' '));}
    Matrix operator* (const Matrix& rhs) const{
		Matrix res = Matrix(r, rhs.c);
		for(LL i = 0;i < res.r;i++)
		for(LL j = 0;j < res.c;j++)
			for(LL k = 0;k < c;k++)
				res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD;
		return res;
	}
};
LL calc_inv(LL num)
{
    LL ans = 1, base = num, expo = MOD-2;
    while(expo)
    {
        if(expo & 1)
            ans = (1LL * ans * base) % MOD;
        expo >>= 1;
        base = 1LL * base * base % MOD;
    }
    return ans;
}
LL D, n;
Matrix matrix_inv(Matrix A)
{
    Matrix A_inv = A, A_copy = A;
    A_inv.unitize();
    for(LL i = 0;i < n;i++)
    {
        if(A_copy.a[i][i] == 0)
            for(LL i2 = i+1;i2 < n;i2++)
                if(A_copy.a[i2][i])
                {
                    A_copy.swap_row(i, i2);
                    A_inv.swap_row(i, i2);
                    break;
                }
        // if(A_copy.a[i][i] == 0) return false; // impossible
        A_inv.mul_row(i, calc_inv(A_copy.a[i][i]));A_copy.mul_row(i, calc_inv(A_copy.a[i][i]));
        for(LL i2 = i+1;i2 < n;i2++)
            {A_inv.mul_and_add(i, i2, -A_copy.a[i2][i]);A_copy.mul_and_add(i, i2, -A_copy.a[i2][i]);}
    }
    for(LL i = n-2;i >= 0;i--)
        for(LL i2 = i+1;i2 < n;i2++)
        {
            A_inv.mul_and_add(i2, i, -A_copy.a[i][i2]);
            A_copy.mul_and_add(i2, i, -A_copy.a[i][i2]);
        }
    return A_inv;
}
Matrix fun(Matrix A) // A -> E-A
{
    Matrix B = A;
    for(LL i = 0;i < B.r;i++)
    {
        for(LL j = 0;j < B.c;j++)
            B.a[i][j] = ((-B.a[i][j])%MOD+MOD)%MOD;
        B.a[i][i] = (B.a[i][i] + 1LL) % MOD;
    }
    return B;
}
int main()
{
    LL T;
    scanf("%lld", &T);
    while(T--)
    {
        LL ans[maxn];
        memset(ans, 0, sizeof(ans));
        scanf("%lld%lld", &D, &n);
        Matrix A = Matrix(n, n);
        for(LL son = 0;son < 2;son++)
            for(LL i = 0;i < n;i++)
            {
                LL color;
                scanf("%lld", &color);
                A.a[i][color-1]++;
            }
        Matrix A_inv = A;
        A_inv = fun(A_inv);
        A_inv = matrix_inv(A_inv);
        D++;
        Matrix base = A, A_n = A;
        A_n.unitize();
        while(D)
        {
            if(D & 1LL)
                A_n = A_n * base;
            D >>= 1LL;
            base = base * base;
        }
        A_n = fun(A_n);
        A = A_n * A_inv;
        for(LL i = 0;i < n;i++)
        for(LL j = 0;j < n;j++)
            ans[j] = (ans[j] + A.a[i][j]) % MOD;
        for(LL i = 0;i < n;i++)
            printf("%lld%c", ans[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}
