#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
struct Obj{
    int d1, d2, h;
}actors[maxn], pairs[maxn];
bool cmp(Obj& lhs, Obj& rhs)
{
    return lhs.d1 > rhs.d1 || (lhs.d1 == rhs.d1 && lhs.d2 > rhs.d2);
}
int s[maxn];
int main()
{
    int T, n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
            scanf("%d%d%d", &actors[i].d1, &actors[i].d2, &actors[i].h);
        for(int i = 0;i < m;i++)
        {
            int h1, h2;
            scanf("%d%d%d", &pairs[i].d1, &pairs[i].d2, &h1, &h2);
            pairs[i].h = h2 - h1;
        }
        sort(actors, actors + n, cmp);
        sort(pairs, pairs + n, cmp);
        int i = 0, j = 0, t = 0, ans = 0;
        while(i < n)
        {
            while(j < n
            && pairs[j].d1 >= actors[i].d1)
            {
                if(t && )
            }
        }
    }
    return 0;
}