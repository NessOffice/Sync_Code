#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 5e3 + 5; // 2**20 > 2*maxn // caution!
int table[maxn][20];
using namespace std;
int main()
{
    memset(table, -1, sizeof(table));
    int n, m, maxy = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        table[l][0] = max(table[l][0], r); // jump one time
        maxy = max(maxy, r); // find the biggest element
    }
    int last = 1;
    for(int i = 1;i <= maxy;i++)
    {
        if(table[i][0] == -1 && table[last][0] >= i) // update the points in the middle
            table[i][0] = table[last][0];
        if(table[i][0] > table[last][0]) // update the left endpoint
            last = i;
    }
    for(int i = 1, len = 1;len <= maxy;i++, (len <<= 1)) // 2**i for the number of jumps
        for(int j = 1;j <= maxy;j++) // caution! not j + len <= n!
        {
            if(table[j][i-1] == -1) // a point that isn't in any section
                table[j][i] = -1;
            else
                table[j][i] = table[table[j][i-1]][i-1]; // doubling algorithm
        }
    while(m--)
    {
        int x, y, ans = 0;
        scanf("%d%d", &x, &y);
        while(ans != -1)
        {
            int end = table[x][0];
            if(end == -1)
            {
                ans = -1;
                break;
            }
            if(end >= y)
            {
                ans += 1;
                break;
            }
            for(int i = 0;;i++)
            {
                if(table[x][i] >= y) // table[x][i-1] < y <= table[x][i]
                {
                    ans += (1 << (i-1));
                    x = table[x][i-1];
                    break;
                }
                if(table[x][i] == table[x][i+1])
                {
                    x = table[x][i]; // reach a fixed point, and table[x][i] < y
                    ans = -1;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}