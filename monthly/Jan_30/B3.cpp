#include <cstdio>
#include <cmath>
int T, x[5], y[5], v[4];
double l1, r1, l2, r2, t1, t2, t3, dx1, dy1, dx2, dy2, lam1, lam2, ans;
double fun2(double lam)
{
    dx2 = lam*x[3] + (1-lam)*x[2];
    dy2 = lam*y[3] + (1-lam)*y[2];
    t2 = sqrt((dx2-x[3])*(dx2-x[3])+(dy2-y[3])*(dy2-y[3]))/v[1];
    t3 = sqrt((dx1-dx2)*(dx1-dx2)+(dy1-dy2)*(dy1-dy2))/v[2];
    if(ans > t1+t2+t3) ans = t1+t2+t3;
    return t1 + t2 + t3;
}
double fun1(double lam)
{
    l2 = 0, r2 = 1, lam2 = 0.5;
    dx1 = lam*x[0] + (1-lam)*x[1];
    dy1 = lam*y[0] + (1-lam)*y[1];
    t1 = sqrt((dx1-x[0])*(dx1-x[0])+(dy1-y[0])*(dy1-y[0]))/v[0];
    while(r2 - l2 > 1e-8)
    {
        double temp = fun2((lam2+l2)/2);
        if(temp > fun2(lam2+r2)/2){l2 = lam2;lam2 = (l2+r2)/2;}
        else{r2 = lam2;lam2 = (l2+r2)/2;}
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ans = 10e9;
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        scanf("%d%d%d%d", &x[2], &y[2], &x[3], &y[3]);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        l1 = 0, r1 = 1, lam1 = 0.5;
        while(r1-l1>1e-8)
        {
            double temp = fun1((lam1+l1)/2);
            if(temp > fun1(lam1+r1)/2){l1 = lam1;lam1 = (l1+r1)/2;}
            else{r1 = lam1;lam1 = (l1+r1)/2;}
        }
        printf("%lf", ans);
    }
    return 0;
}