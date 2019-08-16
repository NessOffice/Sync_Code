#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 5e4 + 5;
int cols[maxn], rows[maxn];
char grids[maxn], grids_max[maxn];
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
            rows[i] = 0;
        for(int j = 0;j < m;j++)
            cols[j] = 0;
        int i_max = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%s", grids);
            for(int j = 0;j < m;j++)
                if(grids[j] == '*')
                {
                    rows[i]++;
                    cols[j]++;
                }
            if(i == 0 || rows[i] > rows[i_max])
            {
                for(int j = 0;j < m;j++)
                    grids_max[j] = grids[j];
                i_max = i;
            }
            else if(rows[i] == rows[i_max])
            {
                for(int j = 0;j < m;j++)
                    if(grids[j] == '.')
                        grids_max[j] = grids[j];
            }
        }
        int j_max = 0;
        for(int j = 0;j < m;j++)
            if(cols[j] > cols[j_max]) j_max = j;
        int center = 0;
        if(grids_max[j_max] == '.') center = 1;
        for(int j = 0;j < m && center == 0;j++)
            if(cols[j] == cols[j_max])
                if(grids_max[j] == '.')
                    center = 1;
        int ans = m - rows[i_max] + n - cols[j_max] - center;
        printf("%d\n", ans);
    }
    return 0;
}