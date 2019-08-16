#include <cstdio>
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int a = 1;a*a <= n;a++)
        ans += (1+2*(n/a-a));
    printf("%d\n", ans);
}
