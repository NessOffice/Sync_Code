#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const double eps = 1e-10;
double heron(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    int a, b, c, d;
    double ans = 0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for(int i = 0;i < 3;i++)
    {
        if(i == 1) swap(b, c);
        if(i == 2) swap(b, d);
        double l = max(abs(b-a), abs(d-c)), r = min(a+b, c+d);
        while(r - l > eps)
        {
            double ml = l + (r - l) / 3;
            double mr = r - (r - l) / 3;
            double sl = heron(a, b, ml) + heron(c, d, ml);
            double sr = heron(a, b, mr) + heron(c, d, mr);
            if(sl < sr) l = ml;
            else r = mr;
        }
        ans = max(ans, heron(a, b, l) + heron(c, d, l));
    }
    printf("%lf", ans);
    return 0;
}
