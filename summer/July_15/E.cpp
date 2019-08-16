#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct Matrix
{
    double r, c, a[8][8];
    void clr(){memset(a, 0.0, sizeof(a));}
    void swap_row(int i1, int i2){for(int j = 0;j < c;j++) swap(a[i1][j], a[i2][j]);}
    void mul_row(int i, double k){for(int j = 0;j < c;j++) a[i][j] *= k;}
    void mul_and_add(int i1, int i2, double k){for(int j = 0;j < c;j++) a[i2][j] += k*a[i1][j];}
    Matrix operator* (const Matrix& rhs) const{
		Matrix res;
        res.r = r, res.c = rhs.c;
        memset(res.a, 0.0, sizeof(res.a));
		for(int i = 0;i < res.r;i++)
		for(int j = 0;j < res.c;j++)
			for(int k = 0;k < c;k++)
				res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]);
		return res;
	}
}A, B_8, B_33, Query, A_inv;
int n = 8;
bool solve()
{
    for(int i = 0;i < n;i++)
    {
        for(int i2 = i+1;i2 < n;i2++)
            if(fabs(A.a[i2][i]) > fabs(A.a[i][i]))
            {
                A.swap_row(i, i2);
                A_inv.swap_row(i, i2);
                break;
            }
        // if(A.a[i][i] == 0) return false;
        A_inv.mul_row(i, 1.0/A.a[i][i]);A.mul_row(i, 1.0/A.a[i][i]);
        for(int i2 = i+1;i2 < n;i2++)
            {A_inv.mul_and_add(i, i2, -A.a[i2][i]);A.mul_and_add(i, i2, -A.a[i2][i]);}
    }
    for(int i = n-2;i >= 0;i--)
        for(int i2 = i+1;i2 < n;i2++)
        {
            A_inv.mul_and_add(i2, i, -A.a[i][i2]);
            A.mul_and_add(i2, i, -A.a[i][i2]);
        }
    return true;
}
int main()
{
    double x[4], y[4], u[4], v[4], x_query, y_query;
    A.r = A.c = A_inv.r = A_inv.c = 8;
    B_8.r = 8, B_8.c = 1;
    B_33.r = B_33.c = 3;
    Query.r = 3, Query.c = 1;
    while(scanf("%lf%lf%lf%lf", &x[0], &y[0], &u[0], &v[0]) == 4)
    {
        scanf("%lf%lf%lf%lf", &x[1], &y[1], &u[1], &v[1]);
        scanf("%lf%lf%lf%lf", &x[2], &y[2], &u[2], &v[2]);
        scanf("%lf%lf%lf%lf", &x[3], &y[3], &u[3], &v[3]);
        scanf("%lf%lf", &x_query, &y_query);
        A.clr();A_inv.clr();B_33.clr();B_8.clr();Query.clr();
        B_8.a[0][0] = u[0];
        B_8.a[1][0] = v[0];
        B_8.a[2][0] = u[1];
        B_8.a[3][0] = v[1];
        B_8.a[4][0] = u[2];
        B_8.a[5][0] = v[2];
        B_8.a[6][0] = u[3];
        B_8.a[7][0] = v[3];
        Query.a[0][0] = x_query, Query.a[1][0] = y_query, Query.a[2][0] = 1;
        double m[8][8] = 
        {
            {x[0], y[0], 1,    0,    0, 0, -x[0]*u[0], -y[0]*u[0]},
            {   0,    0, 0, x[0], y[0], 1, -x[0]*v[0], -y[0]*v[0]},
            {x[1], y[1], 1,    0,    0, 0, -x[1]*u[1], -y[1]*u[1]},
            {   0,    0, 0, x[1], y[1], 1, -x[1]*v[1], -y[1]*v[1]},
            {x[2], y[2], 1,    0,    0, 0, -x[2]*u[2], -y[2]*u[2]},
            {   0,    0, 0, x[2], y[2], 1, -x[2]*v[2], -y[2]*v[2]},
            {x[3], y[3], 1,    0,    0, 0, -x[3]*u[3], -y[3]*u[3]},
            {   0,    0, 0, x[3], y[3], 1, -x[3]*v[3], -y[3]*v[3]},
        };
        for(int i = 0;i < 8;i++)
        for(int j = 0;j < 8;j++)
            A.a[i][j] = m[i][j],
            A_inv.a[i][i] = 1;
        solve();
        B_8 = A_inv * B_8;
        B_33.a[0][0] = B_8.a[0][0], B_33.a[0][1] = B_8.a[1][0], B_33.a[0][2] = B_8.a[2][0];
        B_33.a[1][0] = B_8.a[3][0], B_33.a[1][1] = B_8.a[4][0], B_33.a[1][2] = B_8.a[5][0];
        B_33.a[2][0] = B_8.a[6][0], B_33.a[2][1] = B_8.a[7][0], B_33.a[2][2] =           1;
        Query = B_33 * Query;
        printf("%lf\n%lf\n", Query.a[0][0]/Query.a[2][0], Query.a[1][0]/Query.a[2][0]);
    }
    return 0;
}
/*
0.00 0.00 0.00 0.00
4.00 0.00 4.00 0.00
4.00 4.00 5.00 2.00
0.00 4.00 2.00 3.00
2.00 2.00
0.00 0.00 1.00 0.00
0.00 10.00 -0.79 8.17
-10.00 -10.00 4.95 -50.99
10.00 -10.00 3.51 -6.73
15.00 -15.00
*/