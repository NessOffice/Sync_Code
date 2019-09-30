#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 5;
int pos_new[60][60], pos_old[60][60], ans[60], vis[60];
char s1[60], s2[60];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i < 60;i++)
        for(int j = 0;j < 60;j++)
            pos_old[i][j] = 1;
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
        {
            scanf("%s", s1);
            scanf("%s", s2);
            memset(pos_new, 0, sizeof(pos_new));
            for(int j = 0;j < m;j++)
                pos_new[s2[j]-'a'][j] = 1;
            for(int j = 0;j < m;j++)
            {
                int ch = s1[j] - 'a';
                for(int k = 0;k < m;k++)
                    pos_old[j][k] &= pos_new[ch][k];
            }
        }
        bool yes = true;
        for(int j = 0;j < m;j++)
        {
            int k;
            for(k = 0;k < m;k++)
            {
                if(pos_old[j][k] && !vis[k])
                {
                    ans[j] = k+1;
                    vis[k] = 1;
                    break;
                }
            }
            if(k == m)
                yes = false;
        }
        if(yes){
            for(int j = 0;j < m;j++)
            {
                if(j) putchar(' ');
                printf("%d", ans[j]);
            }
            putchar('\n');
        }else
            printf("-1\n");
    }
    return 0;
}
/*
2
6
1 2
3 3
3 4
4 4
5 6
7 7
2
1 10
20 30
*/