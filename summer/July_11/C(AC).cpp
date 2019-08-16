#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 105;
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
int main()
{
    LL T, D, n;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld", &D, &n);
        Matrix A = Matrix(2*n, 2*n), B = Matrix(2*n, 2*n);
        for(LL son = 0;son < 2;son++)
            for(LL i = 0;i < n;i++)
            {
                LL color;
                scanf("%lld", &color);
                A.a[i][color-1]++;
                A.a[i+n][i] = 1;
                A.a[i+n][i+n] = 1;
            }
        for(LL i = 0;i < n;i++)
            B.a[0][i+n] = 1;
        D++;
        Matrix base = A, A_n = Matrix(2*n, 2*n);
        A_n.unitize();
        while(D)
        {
            if(D & 1LL)
                A_n = A_n * base;
            D >>= 1LL;
            base = base * base;
        }
        Matrix ans = B * A_n;
        for(LL i = 0;i < n;i++)
            printf("%lld%c", ans.a[0][i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}

/*
2

1 2
1 2
1 1

0 3
1 2 3
2 2 1


*/