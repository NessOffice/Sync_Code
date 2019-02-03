#include <cstdio>
#include <cstring>
int main()
{
    int T, ans;
    int cnt[12][30];
    int sum[100010];
    char str[100010][12];
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        int n;
        scanf("%d", &n);
        scanf("%s", str[0]);
        int len = strlen(str[0]);
        for(int j = 0;j < len;j++)
            cnt[j][str[0][j]-'a']++;
        for(int i = 1;i < n;i++)
        {
            scanf("%s", str[i]);
            for(int j = 0;j < len;j++)
                cnt[j][str[i][j]-'a']++;
        }
        ans = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < len;j++)
                sum[i] += (n - cnt[j][str[i][j]-'a']);
            if(sum[i] < sum[ans]) ans = i;
        }
        printf("%s\n", str[ans]);
    }
    return 0;
}