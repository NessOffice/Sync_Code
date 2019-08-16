#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxk = 30;
const int maxn = 2e3 + 5;
int n, m;
char grids[maxn][maxn];
int r1[maxk], r2[maxk], c1[maxk], c2[maxk];
bool row_occupied[maxn], col_occupied[maxn];
int num_of_row_occupied, num_of_col_occupied;
bool check(int k)
{
    char current_char = 'a' + k - 1;
    num_of_row_occupied = num_of_col_occupied = 0;
    for(int i = 1;i <= n;i++)
        row_occupied[i] = false;
    for(int j = 1;j <= m;j++)
        col_occupied[j] = false;

    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= m;j++)
    {
        if(grids[i][j] != current_char) continue;
        if(row_occupied[i] == false)
        {
            row_occupied[i] = true;
            num_of_row_occupied++;
        }
        if(col_occupied[j] == false)
        {
            col_occupied[j] = true;
            num_of_col_occupied++;
        }
    }

    if(num_of_row_occupied > 1 && num_of_col_occupied > 1)
        return false;
    if(num_of_row_occupied == 0 && num_of_col_occupied == 0)
    {
        r1[k] = r2[k] = r1[k+1];
        c1[k] = c2[k] = c1[k+1];
        return true;
    }
    if(num_of_row_occupied == 1)
    {
        c1[k] = c2[k] = -1;
        int r = 1;
        while(row_occupied[r] == false) r++;
        r1[k] = r2[k] = r;
        for(int j = 1;j <= m && c1[k] == -1;j++)
            if(grids[r][j] == current_char) c1[k] = j;
        for(int j = m;j >= 1 && c2[k] == -1;j--)
            if(grids[r][j] == current_char) c2[k] = j;
        for(int j = c1[k];j <= c2[k];j++)
            if(grids[r][j] == '.' || grids[r][j] < current_char)
                return false;
    }
    if(num_of_col_occupied == 1)
    {
        r1[k] = r2[k] = -1;
        int c = 1;
        while(col_occupied[c] == false) c++;
        c1[k] = c2[k] = c;
        for(int i = 1;i <= n && r1[k] == -1;i++)
            if(grids[i][c] == current_char) r1[k] = i;
        for(int i = n;i >= 1 && r2[k] == -1;i--)
            if(grids[i][c] == current_char) r2[k] = i;
        for(int i = r1[k];i <= r2[k];i++)
            if(grids[i][c] == '.' || grids[i][c] < current_char)
                return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n;i++)
            scanf("%s", grids[i] + 1);

        int num_of_snakes = 0;
        for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(grids[i][j] != '.')
                num_of_snakes = max(num_of_snakes, int(grids[i][j] - 'a' + 1));

        bool flag = true;
        for(int i = num_of_snakes;i > 0 && flag;i--)
            if(check(i) == false) flag = false;

        printf("%s\n", flag ? "YES" : "NO");
        if(flag)
        {
            printf("%d\n", num_of_snakes);
            for(int i = 1;i <= num_of_snakes;i++)
                printf("%d %d %d %d\n", r1[i], c1[i], r2[i], c2[i]);
        }
    }
    return 0;
}
