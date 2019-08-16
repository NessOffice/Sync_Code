#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e3+5; // 
const double PI = 4*atan(1);
int r[maxn], d[maxn];
double prob[maxn];
int main()
{
    int n, r_last;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", r + i);
    d[1] = 0;
    for(int i = 2;i <= n;i++)
        scanf("%d", d + i);
    prob[0] = 1;
    for(int i = 1;i < n;i++)
    {
        double theta1 = acos(1.0*(abs(r[i]+r[i+1]))/(1.0*(d[i+1]-d[i])));
        double theta2 = acos(1.0*(abs(r[i]-r[i+1]))/(1.0*(d[i+1]-d[i])));
        if(r[i] < r[i+1]) theta2 = PI - theta2;
        prob[i] = prob[i-1] * 2 * (theta2 - theta1) / PI;
        prob[i-1] = prob[i-1] * (1-prob[i]);
    }
    double ans = 0.0;
    for(int i = 0;i < n;i++)
        ans = ans + 1.0*i*prob[i];
    printf("%lf", ans);
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
20 40 60 80 100 120 140 160 180
*/