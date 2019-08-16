#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = (1 << 30);
int T, n, m, ans, cnt;
struct Node{int d1, d2, type, h;}nodes[maxn<<1];
bool cmp_by_d1(const Node& lhs, const Node& rhs)
{
    if(lhs.d1 != rhs.d1) return lhs.d1 < rhs.d1;
    if(lhs.d2 != rhs.d2) return lhs.d2 < rhs.d2;
    if(lhs.type != rhs.type) return lhs.type < rhs.type;
    return false;
}
bool cmp_by_d2(const Node& lhs, const Node& rhs){return lhs.d2 < rhs.d2;}
void divide_and_conquer(int l, int r)
{
    if(l == r) return;
    int mid = (l + r) / 2;

    divide_and_conquer(l, mid);
    divide_and_conquer(mid+1, r);

    sort(nodes+l, nodes+mid+1, cmp_by_d2);
    sort(nodes+mid+1, nodes+r+1, cmp_by_d2);

    int lft = l-1, mx = -INF;
    for(int rgt = mid+1;rgt <= r;rgt++)
    {
        if(nodes[rgt].type == 0) continue;
        while(lft+1 <= mid && nodes[lft+1].d2 <= nodes[rgt].d2)
            if(nodes[++lft].type == 0)
                mx = max(mx, nodes[lft].h);
        ans = max(ans, mx + nodes[rgt].h);
    }
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        cnt = n + m, ans = 0;
        for(int i = 0;i < cnt;i++)
        {
            int h1, h2;
            scanf("%d%d", &nodes[i].d1, &nodes[i].d2);
            if(i < n) scanf("%d", &nodes[i].h);
            else{scanf("%d%d", &h1, &h2); nodes[i].h = h2 - h1;}
            nodes[i].type = (i < n ? 0 : 1); // 0 for elderman, 1 for pants
        }
        sort(nodes, nodes + cnt, cmp_by_d1);
        divide_and_conquer(0, cnt-1);
        printf("%d\n", ans);
    }
    return 0;
}