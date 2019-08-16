#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL MOD_minus1 = 1e9 + 6;
struct Matrix
{
	LL a[33][33];
	LL r, c;
	Matrix(LL r, LL c):r(r), c(c){memset(a, 0, sizeof(a));}
	Matrix operator* (const Matrix& rhs) const{
		Matrix res = Matrix(r, rhs.c);
		for(LL i = 0;i < res.r;i++)
		for(LL j = 0;j < res.c;j++)
			for(LL k = 0;k < c;k++)
				res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD_minus1; // caution!
		return res;
	}
};
LL qpow_matrix(LL expo, LL type)
{
    Matrix ans = Matrix(3, 1), base = Matrix(3, 3);
    if(type == 0){
        ans.a[0][0] = 3;
        ans.a[1][0] = 2;
        ans.a[2][0] = 1;
    }else if(type == 1){
        ans.a[0][0] = 0;
        ans.a[1][0] = 0;
        ans.a[2][0] = 1;
    }else if(type == 2){
        ans.a[0][0] = 0;
        ans.a[1][0] = 1;
        ans.a[2][0] = 0;
    }else if(type == 3){
        ans.a[0][0] = 1;
        ans.a[1][0] = 0;
        ans.a[2][0] = 0;
    }
    base.a[0][0] = base.a[0][1] = base.a[0][2] = 1;
    base.a[1][0] = 1;
    base.a[2][1] = 1;
    while(expo)
    {
        if(expo & 1LL)
            ans = base * ans;
        expo >>= 1LL;
        base = base * base;
    }
    return ans.a[0][0];
}
LL qpow_num(LL expo, LL base)
{
    LL ans = 1LL;
    while(expo)
    {
        if(expo & 1LL)
            ans = base * ans % MOD;
        expo >>= 1LL;
        base = base * base % MOD;
    }
    return ans % MOD;
}
int main()
{
	LL n, f1, f2, f3, c, ans;
    scanf("%lld%lld%lld%lld%lld", &n, &f1, &f2, &f3, &c);
    if(n == 1) printf("%lld", f1 % MOD);
    else if(n == 2) printf("%lld", f2 % MOD);
    else if(n == 3) printf("%lld", f3 % MOD);
    else{
        n -= 3;
        LL expo1 = qpow_matrix(n, 0) - n - 3; // caution!
        expo1 = ((expo1 % MOD_minus1) + MOD_minus1) % MOD_minus1;
        ans = qpow_num(expo1, c) % MOD;
        ans = ans * qpow_num(qpow_matrix(n, 1), f1) % MOD;
        ans = ans * qpow_num(qpow_matrix(n, 2), f2) % MOD;
        ans = ans * qpow_num(qpow_matrix(n, 3), f3) % MOD;
        printf("%lld", ans);
    }
    return 0;
}
