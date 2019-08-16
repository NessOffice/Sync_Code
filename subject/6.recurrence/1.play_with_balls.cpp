#include <cstdio>
#include <cstring>
typedef long long LL;
LL n, m;
struct Matrix
{
	LL a[33][33];
	LL r, c;
	Matrix(int r, int c):r(r), c(c){memset(a, 0, sizeof(a));}
	Matrix operator* (const Matrix& rhs) const{
		Matrix res = Matrix(r, rhs.c);
		for(LL i = 0;i < res.r;i++)
		for(LL j = 0;j < res.c;j++)
			for(LL k = 0;k < c;k++)
				res.a[i][j] += a[i][k] * rhs.a[k][j];
		return res;
	}
};
LL qpow(LL expo)
{
    Matrix ans = Matrix(n, n), base = Matrix(n, n);
	for(int i = 0;i < n;i++)
		ans.a[i][i] = 1;
	for(int i = 0;i < n;i++)
	{
		base[]
	}
		base.a[i][(i+n-1)%n] = base.a[i][(i+1)%n] = 1;
    while(expo)
    {
        if(expo & 1)
            ans = ans * base;
        expo >>= 1;
        base = base * base;
    }
    return ans.a[0][0];
}
int main()
{
	scanf("%lld%lld", &n, &m);
	printf("%lld\n", qpow(m));
	return 0;
}
