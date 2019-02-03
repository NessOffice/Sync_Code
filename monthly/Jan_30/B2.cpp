#include <cstdio>
int T, x[5], y[5], v[4];
double l1, r1, l2, r2, dx1, dx2, dy1, dy2;
double fun()
{
    double t = 0;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
        scanf("%d%d%d%d", &x[2], &y[2], &x[3], &y[3]);
        scanf("%d%d%d", &v[0], &v[0], &v[2]);
        int sure1 = 0, sure2 = 0;
        if(v[2] > v[1]) dx2 = x[3], dy2 = y[3], sure2 = 1;
        if(v[2] > v[0]) dx1 = x[0], dy1 = y[0], sure1 = 1;
        if(!sure1)
        {

        }
        if(!sure2)
        {

        }
        if(!sure1 && !sure2)
        {

        }
    }
    return 0;
}