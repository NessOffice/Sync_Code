#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 5;
const double eps = 1e-6;
const double INF = 1e20;
int a[maxn];
double calc_square(double a1, double a2, double a3)
{
    double p = (a1 + a2 + a3) / 2;
    return p*(p-a1)*(p-a2)*(p-a3);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        double ans = INF;
        bool no = true;
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for(int i = n-1;i >= 2;i--)
        {
            for(int j = i-1;j >= 1;j--)
            {
                if(a[j] <= a[i] / 2) break;
                int k = lower_bound(a, a+j, a[i]-a[j]+1) - a;
                if(k >= j) continue;
                double s = calc_square(a[i], a[j], a[k]);
                no = false;
                ans = min(ans, s);
            }
        }
        if(no) printf("-1\n");
        else printf("%lf\n", ans);
    }
    return 0;
}
/*
4
3 3
1 2 3
4 4
1 2 3 4
3 11
5 7 11
6 11
5 7 8 9 10 11
*/