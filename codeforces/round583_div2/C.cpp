#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e6+5;
struct Node{LL r, c;};
vector<bool> grid[maxn];
vector<bool> vis[2][maxn];
char grid_str[maxn];
vector<Node> q[2][maxn<<1];
LL sz[maxn];
LL n, m;
LL bfs()
{
    LL mn = 2;
    q[0][0].push_back((Node){0, 0});
    for(LL d = 1;d <= n+m-3;d++)
    {
        for(LL j = q[0][d-1].size()-1;j >= 0;j--)
        {
            Node u = q[0][d-1][j];
            if(u.r < n-1 && grid[u.r+1][u.c] && !vis[0][u.r+1][u.c])
                vis[0][u.r+1][u.c] = true,
                q[0][d].push_back((Node){u.r+1, u.c});
            if(u.c < m-1 && grid[u.r][u.c+1] && !vis[0][u.r][u.c+1])
                vis[0][u.r][u.c+1] = true,
                q[0][d].push_back((Node){u.r, u.c+1});
        }
        mn = min(mn, (LL)q[0][d].size());
        if(mn == 0) break;
    }
    q[1][n+m-2].push_back((Node){n-1, m-1});
    for(LL d = n+m-3;d >= 1;d--)
    {
        for(LL j = q[1][d+1].size()-1;j >= 0;j--)
        {
            Node u = q[1][d+1][j];
            // if(u.r > 0 && grid[u.r-1][u.c] && !vis[1][u.r-1][u.c])
            if(u.r > 0 && vis[0][u.r-1][u.c] && !vis[1][u.r-1][u.c])
                vis[1][u.r-1][u.c] = true,
                q[1][d].push_back((Node){u.r-1, u.c});
            // if(u.c > 0 && grid[u.r][u.c-1] && !vis[1][u.r][u.c-1])
            if(u.c > 0 && vis[0][u.r][u.c-1] && !vis[1][u.r][u.c-1])
                vis[1][u.r][u.c-1] = true,
                q[1][d].push_back((Node){u.r, u.c-1});
        }
        mn = min(mn, (LL)q[1][d].size());
        if(mn == 0) break;
    }
    return mn;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for(LL i = 0;i < n;i++)
    {
        scanf("%s", grid_str);
        for(LL j = 0;j < m;j++)
            grid[i].push_back(grid_str[j] == '.'),
            vis[0][i].push_back(false),
            vis[1][i].push_back(false);
    }
    printf("%lld", bfs());
    return 0;
}
/*
3 3
..#
..#
#..

4 4
..##
....
....
..#.

6 8
........
...#.#..
.......#
..#.##.#
..#.....
...#....

6 7
.......
.....##
....#..
..#....
##.....
.......
*/