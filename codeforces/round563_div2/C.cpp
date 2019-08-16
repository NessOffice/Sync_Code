#include <cstdio>
#include <cstring>
const int maxn = 1e5 + 5;
int main()
{
    int n;
    scanf("%d", &n);
    bool isP[maxn];
    int P[maxn], ans[maxn];
    int total = 0;
    memset(isP, true, sizeof(isP));
    memset(P, 0, sizeof(P));
    memset(ans, 0, sizeof(ans));
    isP[0] = isP[1] = false;
    for(int i = 2;i <= n;i++)
    {
        if(isP[i])
        {
            P[++total] = i;
            ans[i] = total;
        }
        for(int j = 1;j <= total && i*P[j] <= n;j++)
        {
            isP[i*P[j]] = false;
            ans[i*P[j]] = ans[P[j]];
            if(!(i%P[j])) break;
            
        }
    }
    for(int i = 2;i <= n;i++)
    {
        if(i != 2) putchar(' ');
        printf("%d", ans[i]);
    }
    return 0;
}