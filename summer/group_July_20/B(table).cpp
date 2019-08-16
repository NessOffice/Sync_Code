#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int ans[5][5][5], table[5][5], col2row[5], fst; // col2row: col2row
int r_now, c_now;
set<pair<int, int> > s;
int judge(int nr, int nc)
{
    if(nr >= 3 && table[nr][nc] == table[nr-1][nc] && table[nr][nc] == table[nr-2][nc]) return table[nr][nc]; // vertical

    if(nc >= 3 && table[nr][nc] == table[nr][nc-1] && table[nr][nc] == table[nr][nc-2]) return table[nr][nc]; // horizontal
    if(nc <= 2 && table[nr][nc] == table[nr][nc+1] && table[nr][nc] == table[nr][nc+2]) return table[nr][nc]; // horizontal
    if(2 <= nc && nc <= 3 && table[nr][nc] == table[nr][nc-1] && table[nr][nc] == table[nr][nc+1]) return table[nr][nc]; // horizontal

    if(nr >= 3 && nc >= 3 && table[nr][nc] == table[nr-1][nc-1] && table[nr][nc] == table[nr-2][nc-2]) return table[nr][nc]; // diagnostical
    if(nr >= 3 && nc <= 2 && table[nr][nc] == table[nr-1][nc+1] && table[nr][nc] == table[nr-2][nc+2]) return table[nr][nc]; // diagnostical
    if(nr <= 2 && nc >= 3 && table[nr][nc] == table[nr+1][nc-1] && table[nr][nc] == table[nr+2][nc-2]) return table[nr][nc]; // diagnostical
    if(nr <= 2 && nc <= 2 && table[nr][nc] == table[nr+1][nc+1] && table[nr][nc] == table[nr+2][nc+2]) return table[nr][nc]; // diagnostical
    if(2 <= nr && nr <= 3 && 2 <= nc && nc <= 3 && table[nr][nc] == table[nr-1][nc-1] && table[nr][nc] == table[nr+1][nc+1]) return table[nr][nc]; // diagnostical
    if(2 <= nr && nr <= 3 && 2 <= nc && nc <= 3 && table[nr][nc] == table[nr-1][nc+1] && table[nr][nc] == table[nr+1][nc-1]) return table[nr][nc]; // diagnostical
    return -1;
}
int encode()
{
    int res = 0;
    for(int i = 1;i <= 4;i++)
    for(int j = 1;j <= 4;j++)
    {
        res *= 3;
        res += (table[i][j] + 1);
    }
    return res;
}
void dfs(int player)
{
    for(int col = 1;col <= 4;col++)
    {
        if(col2row[col] > 4) continue;
        r_now = col2row[col]++;
        c_now = col;
        table[r_now][c_now] = player;
        int res = judge(r_now, c_now);
        if((res == 1) && !s.count(make_pair(encode(), 25*fst+5*r_now+c_now)))
        {
            s.insert(make_pair(encode(), 25*fst+5*r_now+c_now));
            ans[fst][r_now][c_now]++;
        }
        if(res == -1) dfs(1^player);
        table[--col2row[col]][col] = -1;
    }
}
int main()
{
    memset(ans, 0, sizeof(ans));
    for(fst = 1;fst <= 4;fst++) // first step;
    {
        memset(table, -1, sizeof(table));
        col2row[1] = col2row[2] = col2row[3] = col2row[4] = 1;
        table[col2row[fst]++][fst] = 0;
        dfs(1);
    }
    for(int i = 1;i <= 4;i++)
    for(int j = 1;j <= 4;j++)
    for(int k = 1;k <= 4;k++)
        printf("%d, ", ans[i][j][k]);
    return 0;
}
/*
0, 287, 311, 80, 96, 609, 675, 76, 315, 543, 455, 351, 342, 188, 204, 286, 47, 0, 175, 55, 94, 630, 516, 69, 431, 364, 615, 171, 177, 252, 116, 172, 55, 175, 0, 47, 69, 516, 630, 94, 171, 615, 364, 431, 172, 116, 252, 177, 80, 311, 287, 0, 76, 675, 609, 96, 351, 455, 543, 315, 286, 204, 188, 342
*/