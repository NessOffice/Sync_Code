#include <cstdio>
int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) == 3)
    {
        double ans = 1.0/(a+b)/(a+b-c-1)*(a*b+b*b-b);
        printf("%.5lf\n", ans);
    }
    return 0;
}
