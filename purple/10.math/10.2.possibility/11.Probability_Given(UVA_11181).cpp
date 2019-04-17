#include <cstdio>
int n, r, buy[25], kase = 1;
double p[25], ans[25], tot;
void dfs(int d, int r0, double p0)
{
    if(r0 < 0 || n-d < r0) return;
    if(d == n)
    {
        tot += p0;
        for(int i = 0;i < n;i++)
            if(buy[i]) ans[i] += p0;
    }
    buy[d] = 0;
    dfs(d+1, r0, p0*(1-p[d]));
    buy[d] = 1;
    dfs(d+1, r0-1, p0*p[d]);
}
int main()
{
    while(scanf("%d%d", &n, &r) && n)
    {
        tot = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%lf", &p[i]);
            ans[i] = buy[i] = 0;
        }
        dfs(0, r, 1.0);
        printf("Case %d:\n", kase++);
        for(int i = 0; i < n; i++)
            printf("%.6lf\n", ans[i] / tot);
    }
    return 0;
}
