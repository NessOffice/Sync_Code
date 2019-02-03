#include <cstdio>
#include <cmath>
int T, x[5], y[5], v[4];
double l1, r1, l2, r2, t1, t2, t3, dx1, dy1, dx2, dy2;
double fun2(double t)
{
    return t1 + t + sqrt((dx1-dx2)*(dx1-dx2)+(dy1-dy2)*(dy1-dy2))/v[2];
}
double fun1(double t)
{
    l2 = 0, r2 = sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]))/v[1];
    if(r2 < 0) r2 = -r2;
    while(r2 - l2 > 1)
    {
        t3 = fun2((t2+l2)/2);
        if(t3 < fun2((t2+r2)/2)){t3 = fun2((t2+r2)/2);l2 = t2;t1 = (l2+r2)/2;}
        else{r2 = t2;t2 = (l2+r2)/2;}
        if(x[3]<x[2]) dx2 = x[3]+v[1]*t2;
        else dx2 = x[3]-v[1]*t2;
        if(y[3]<y[2]) dy2 = y[3]+v[1]*t2;
        else dy2 = y[3]-v[1]*t2;
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        scanf("%d%d%d%d", &x[2], &y[2], &x[3], &y[3]);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        l1 = 0, r1 = sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]))/v[0];
        if(r1 < 0) r1 = -r1;
        l2 = 0, r2 = sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]))/v[1];
        if(r2 < 0) r2 = -r2;
        t1 = (l1+r1)/2, t2 = (l2+r2)/2;
        while(r1 - l1 > 1)
        {
            double temp;
            temp = fun1((t1+l1)/2);
            if(temp < fun1((t1+r1)/2)){l1 = t1;t1 = (l1+r1)/2;}
            else{r1 = t1;t1 = (l1+r1)/2;}
            if(x[1]>x[0]) dx1 = x[0]+v[0]*t1;
            else dx1 = x[0]-v[0]*t1;
            if(y[1]>y[0]) dy1 = y[0]+v[0]*t1;
            else dy1 = y[0]-v[0]*t1;
        }
        printf("%lf", t1+t2+t3);
    }
    return 0;
}