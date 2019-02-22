#include <cstdio>
#include <cstring>
const int maxm = 100 + 10;
int mark[32][10*maxm], sum[32][10*maxm];
int main()
{
    int T, L[maxm], R[maxm], q[maxm];
    scanf("%d", &T);
    while (T--)
    {
        memset(mark, 0, sizeof(mark));
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d%d", &L[i], &R[i], &q[i]);
            int tempQ = q[i];
            for(int j = 0;j < 30;j++)
            {
                if((tempQ & 1) == 0)
                    mark[j][L[i]] += 1,
                    mark[j][R[i]+1] += -1;
                tempQ >>= 1;
            }
        }
        int cnt, ans[10*maxm];
        memset(ans, 0, sizeof(ans));
        for(int j = 0;j < 30;j++)
        {
            cnt = sum[j][0] = 0;
            for(int i = 1;i <= n;i++)
            {
                cnt += mark[j][i];
                if(!cnt) ans[i] += (1<<j);
                sum[j][i] = sum[j][i-1] + (cnt ? 1 : 0);
            }
        }
        bool ok = true;
        for(int i = 0;i < m && ok;i++)
        {
            int tempQ = q[i];
            for(int j = 0;j < 30;j++)
            {
                if(tempQ & 1)
                if(sum[j][R[i]] - sum[j][L[i]-1] >= R[i]-L[i])
                    ok = false;
                tempQ >>= 1;
            }
        }
        printf("%s\n", ok ? "come on, nice girl!" : "I am a poor guy!");
        if(ok)
        {
            printf("%d", ans[1]);
            for(int i = 2;i <= n;i++)
                printf(" %d", ans[i]);
            putchar('\n');
        }
    }
    return 0;
}