#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
const double eps = 1e-10;
double a[maxn];
LL sum, b[maxn];
bool is_int(double num)
{
    return fabs(num - (LL)num) < eps;
}
int main()
{
    LL n;
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++)
    {
        scanf("%lf", &a[i]);
        b[i] = (LL)(floor(a[i]));
        sum += b[i];
    }
    for(LL i = 0;i < n;i++)
    {
        if(sum == 0) break;
        if(!is_int(a[i]))
            b[i]++, sum++;
    }
    for(LL i = 0;i < n;i++)
        printf("%lld\n", b[i]);
    return 0;
}
