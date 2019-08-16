#include <cstdio>
int cnt(int n)
{
    int num = 0;
    while(n)
        n -= (n & -n),
        num++;
    return num;
}
int main()
{
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    while(cnt(n) > k)
        ans += (n & -n),
        n += (n & -n);
    printf("%d\n", ans);
}
