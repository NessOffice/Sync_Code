#include <cstdio>
#include <cmath>
int T, x[5], y[5], v[4];
const double eps = 1e-12;//md, the problem is about the eps, and 1e-6 results in Wrong Answer
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void get_pos(double& dx, double& dy, double lamb, int flag)
{
    dx = x[flag*2-1]*lamb + x[flag*2]*(1-lamb);
    dy = y[flag*2-1]*lamb + y[flag*2]*(1-lamb);
}
double calc(double lamb1, double lamb2)
{
    double dx1, dx2, dy1, dy2;
    get_pos(dx1, dy1, lamb1, 1);
    get_pos(dx2, dy2, lamb2, 2);
    double t = 0;
    t += dist(x[1], y[1], dx1, dy1)/v[1];
    t += dist(x[4], y[4], dx2, dy2)/v[2];
    t += dist(dx1, dy1, dx2, dy2)/v[3];
    return t;
}
double div(double L, double R, double lamb1, int flag)
{
    if(R-L < eps) return flag ? calc(lamb1, L) : div(0, 1, L, 1);
    double midl = (L+R)/2;
    double midr = (midl+R)/2;
    if(flag){
        if(calc(lamb1, midl) < calc(lamb1, midr)) return div(L, midr, lamb1, 1);
        else return div(midl, R, lamb1, 1);
    }else{
        if(div(0, 1, midl, 1) < div(0, 1, midr, 1)) return div(L, midr, 0, 0);
        else return div(midl, R, 0, 0);
    }
}
int main()
{
    for(scanf("%d", &T);T;T--)
    {
        for(int i = 1;i <= 4;i++)
            scanf("%d%d", &x[i], &y[i]);
        for(int i = 1;i <= 3;i++)
            scanf("%d", &v[i]);
        printf("%lf\n", div(0, 1, 0, 0));
    }
    return 0;
}