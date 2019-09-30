#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(int kase = 1;kase <= T;kase++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        double ans1 = (n > 1) ? 0.5 : 1;
        double ans2;
        if(m == 1) ans2 = 1;
        else ans2 = 1.0*(m+1)/(2*m);
        printf("Case #%d: %lf %lf\n", kase, ans1, ans2);
    }
    return 0;
}
