#include <cstdio>
int main()
{
    int T, a[1010], b[1010];
    scanf("%d", &T);
    while (T--)
    {
        int m, k, ans = 100000;
        scanf("%d%d", &m, &k);
        for(int i = 0;i < m;i++)
            scanf("%d", &a[i]);
        for(int i = 0;i < m;i++)
        {
            scanf("%d", &b[i]);
            if((b[i] + k)/a[i] < ans) ans = (b[i] + k)/a[i];
        }
        int k0 = k;
        while(1)
        {
            for(int i = 0;i < m;i++)
                if(a[i]*ans > b[i]) k0 -= (a[i]*ans-b[i]);
            if(k0 < 0){ans--;k0 = k;}
            else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}