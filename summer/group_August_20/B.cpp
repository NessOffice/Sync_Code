#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
const double EPS = 1e-10;
double mass[maxn], sum_mass[maxn], loc[maxn], sum_ml[maxn], sum_ml2[maxn];
double sum1(LL st, LL ed)
{
    return 0.5*(sum_ml[ed] - sum_ml[st-1] - loc[st]*(sum_mass[ed]-sum_mass[st-1]));
}
double sum2(LL st, LL ed)
{
    return 0.5*(sum_ml2[ed]-sum_ml2[st-1] - 2.0*loc[st]*(sum_ml[ed]-sum_ml[st-1]) + loc[st]*loc[st]*(sum_mass[ed]-sum_mass[st-1]));
}
double sum1_rev(LL st, LL ed)
{
    return 0.5*(loc[ed]*(sum_mass[ed]-sum_mass[st-1]) - (sum_ml[ed]-sum_ml[st-1]));
}
double sum2_rev(LL st, LL ed)
{
    return 0.5*(sum_ml2[ed]-sum_ml2[st-1] - 2.0*loc[ed]*(sum_ml[ed]-sum_ml[st-1]) + loc[st]*loc[st]*(sum_mass[ed]-sum_mass[st-1]));
}
int main()
{
    LL n, L, T, E;
    scanf("%lld%lld%lld%lld", &n, &L, &T, &E);
    for(LL i = 1;i <= n;i++)
    {
        scanf("%lf%lf", loc + i, mass + i);
        sum_mass[i] = sum_mass[i-1] + mass[i];
        sum_ml[i] = sum_ml[i-1] + mass[i]*loc[i];
        sum_ml2[i] = sum_ml2[i-1] + mass[i]*loc[i]*loc[i];
    }
    loc[n+1] = L;
    sum_ml[n+1] = sum_ml[n];
    sum_ml2[n+1] = sum_ml2[n];
    double ans = 0;
    for(LL i = 1;i <= n+1;i++)
    {
        LL l1 = 1, r1 = max(1, i-1);
        double m1, m2;

        double v1 = 0, v2 = 0;
        while(l1 <= r1)
        {
            double En = E, Enn;
            LL mid1 = l1 + r1 >> 1LL;
            if(i > 1)
                m1 = sum_mass[i-1] - sum_mass[mid1-1];
            LL l2 = min(i, n), r2 = n;
            En = En + sum1_rev(mid1, i-1) - sum2_rev(mid1, i-1);
            Enn = En;
            if(En < EPS){r1 = mid1;continue;}
            bool quit1 = (l1 == r1);
            while(l2 <= r2)
            {
                LL mid2 = l2 + r2 >> 1LL;
                m2 = sum_mass[mid2] - sum_mass[i-1];
                Enn = En + sum1(i, mid2) - sum2(i, mid2);
                if(m1 < EPS) v2 = sqrt(2.0*Enn/m2);
                else v2 = sqrt(2.0*Enn*m1/(m2*m2+m1*m2));
                if(Enn < EPS){r2 = mid2;continue;}
                bool quit = (l2 == r2);
                if(quit) break;
                if(v2*T + loc[i] > loc[mid2+1]){
                    if(mid2 == n){v2 = 1.0 * (loc[n+1]-loc[i]) / T;break;}
                    l2 = mid2 + 1;
                }
                else r2 = mid2;
                
            }
            if(m1 < EPS) v1 = 0;
            else v1 = sqrt(2.0*Enn/m1-m2/m1*v2*v2);
            if(quit1) break;
            if(loc[i-1]-v1*T < loc[mid1?mid1-1:0]){
                if(mid1 == 1){v1 = 1.0 * loc[i-1] / T;break;}
                l1 = mid1 + 1;
            }
            else r1 = mid1;
            
        }
        ans = max(ans, loc[i]-loc[i-1] + 1.0*(v1+v2)*T);
    }
    printf("%.12lf", ans);
    return 0;
}
/*
1 4 1 1
2 1

2 6 1 1
2 1
4 1
*/