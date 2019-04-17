#include <cstdio>
const int maxn = 3e7 + 5;
int ans[maxn];
int main()
{
    int T, n;
    for(int c = 1;2*c < maxn;c++)
        for(int a = 2*c;a < maxn;a += c)
            if((a ^ (a-c)) == c) ans[a]++;
    for(int i = 2;i < maxn;i++)
        ans[i] += ans[i-1];
    scanf("%d", &T);
    for(int kase = 1;kase <= T;kase++)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", kase, ans[n]);
    }
    return 0;
}
