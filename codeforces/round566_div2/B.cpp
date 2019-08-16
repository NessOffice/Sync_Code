#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 510;
int main()
{
    int h, w, flag_plus = 1, center_r = -1, center_c = -1;
    int vis[maxn][maxn];
    char mazz[maxn][maxn];
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &h, &w);
    for(int i = 0;i < h;i++)
        scanf("%s", mazz[i]);
    for(int i = 1;i < h-1 && center_r == -1;i++)
    {
        for(int j = 1;j < w-1 && center_c == -1;j++)
        {
            if(mazz[i][j] == '*')
            if(mazz[i][j-1] == '*')
            if(mazz[i][j+1] == '*')
            if(mazz[i-1][j] == '*')
            if(mazz[i+1][j] == '*')
            {
                center_r = i;
                center_c = j;
            }
        }
    }
    if(center_r == -1)
        flag_plus = 0;
    if(flag_plus)
    {
        for(int i = center_r;flag_plus && i >= 0;i--)
        {
            if(mazz[i][center_c] != '*')
                break;
            vis[i][center_c] = 1;
        }
        for(int i = center_r;flag_plus && i < h;i++)
        {
            if(mazz[i][center_c] != '*')
                break;
            vis[i][center_c] = 1;
        }
        for(int j = center_c;flag_plus && j >= 0;j--)
        {
            if(mazz[center_r][j] != '*')
                break;
            vis[center_r][j] = 1;
        }
        for(int j = center_c;flag_plus && j < w;j++)
        {
            if(mazz[center_r][j] != '*')
                break;
            vis[center_r][j] = 1;
        }
    }
    if(flag_plus)
    {
        for(int i = 0;i < h && flag_plus;i++)
        for(int j = 0;j < w && flag_plus;j++)
            if(mazz[i][j] == '*' && vis[i][j] == 0)
                flag_plus = 0;
    }
    printf("%s", flag_plus ? "YES" : "NO");
    return 0;
}