#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
struct Rect{int x1, y1, x2, y2;}rects[maxn];
bool cmp_by_x1(const Rect& lhs, const Rect& rhs){return lhs.x1 < rhs.x1;}
bool cmp_by_y1(const Rect& lhs, const Rect& rhs){return lhs.y1 < rhs.y1;}
bool split(int l, int r)
{
    if(l == r) return true;
    sort(rects + l, rects + r + 1, cmp_by_x1);
    int x2_max = rects[l].x2;
    for(int i = l;i < r;i++)
    {
        x2_max = max(x2_max, rects[i].x2);
        if(rects[i+1].x1 >= x2_max)
            return split(l, i) && split(i+1, r);
    }
    sort(rects + l, rects + r + 1, cmp_by_y1);
    int y2_max = rects[l].y2;
    for(int i = l;i < r;i++)
    {
        y2_max = max(y2_max, rects[i].y2);
        if(rects[i+1].y1 >= y2_max)
            return split(l, i) && split(i+1, r);
    }
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d%d%d%d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
    printf("%s", split(1, n) ? "YES" : "NO");
    return 0;
}
