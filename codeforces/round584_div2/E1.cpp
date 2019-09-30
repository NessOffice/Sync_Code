#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2e6+5;
int a[5][120], maxp[120];
struct Point{int id, val;}point[120];
bool cmp(const Point &lhs, const Point &rhs){return lhs.val > rhs.val;}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int maxi = 0, maxj = 0;
        for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
        {
            scanf("%d", &a[i][j]);
            point[j].id = j;
            point[j].val = max(point[j].val, a[i][j]);
        }
        for(int i = 0;i < n;i++)
        for(int j = m;j < n;j++)
            a[i][j] = 0,
            point[j].id = j,
            point[j].val = max(point[j].val, a[i][j]);
        m = max(m, n);
        sort(point, point+m, cmp);
        int sz;
        if(n == 2) sz = 4;
        if(n == 3) sz = 27;
        if(n == 4) sz = 4*4*4*4;
        int ans = 0;
        for(int i = 0;i < sz;i++)
        {
            int shift[5];
            for(int j = 0;j < n;j++)
            {
                shift[j] = i % n;
                i /= n;
            }
            int now = 0, one = 0;
            for(int j = 0;j < n;j++)
            {
                for(int k = 0;k < n;k++)
                {
                    one = max(a[k][point[j].id])
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
