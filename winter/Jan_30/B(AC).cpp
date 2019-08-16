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
double div2(double l, double r, double lamb1)
{
    if(r-l < eps) return calc(lamb1, l);
    double midl = (l+r)/2.0;
    double midr = (midl+r)/2.0;
    if(calc(lamb1, midl) < calc(lamb1, midr)) return div2(l, midr, lamb1);
    else return div2(midl, r, lamb1);
}
double div1(double l, double r)
{
    if(r-l < eps) return div2(0, 1, l);
    double midl = (l+r)/2.0;
    double midr = (midl+r)/2.0;
    if(div2(0, 1, midl) < div2(0, 1, midr)) return div1(l, midr);
    else return div1(midl, r);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        for(int i = 1;i <= 4;i++)
            scanf("%d%d", &x[i], &y[i]);
        for(int i = 1;i <= 3;i++)
            scanf("%d", &v[i]);
        printf("%lf\n", div1(0, 1));
    }
    return 0;
}