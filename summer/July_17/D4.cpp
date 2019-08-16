#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 5;
const double eps = 1e-6;
const double INF = 1e50;
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
        for(int i = 2;i <= min(10000, n-2);i++)
        {
            for(int j = i-1;j >= 1;j--)
            {
                if(a[j] <= (a[i] / 2)) break;
                int l = 0, r = j-1, target = a[i]-a[j]+1;
                while(l < r)
                {
                    int mid = (l+r)/2;
                    if(a[mid] < target) l = mid+1;
                    else r = mid;
                }
                int k = l;
                if(a[k] + a[j] <= a[i]) continue;
                double s = calc_square(a[i], a[j], a[k]);
                no = false;
                ans = min(ans, s);
            }
        }
        if(no) printf("%lf\n", -1.0);
        else printf("%.12lf\n", sqrt(ans));
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