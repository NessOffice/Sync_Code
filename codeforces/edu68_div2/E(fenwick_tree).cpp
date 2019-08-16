#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long LL;
const int maxn = 1e4+5;
using namespace std;
struct Node{int x1, y1, x2, y2;};
bool cmp_by_y(const Node& lhs, const Node& rhs){return lhs.y2 < rhs.y2;} // both for vert and hori
vector<Node> hori, vert;
int tree[maxn];
int lowbit(int num){return num&(-num);}
void add(int begin)
{
    for(int i = begin;i < maxn;i += lowbit(i))
        tree[i]++;
}
int query(int begin)
{
    int ans = 0;
    for(int i = begin;i > 0;i -= lowbit(i))
        ans += tree[i];
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1 += 5001, y1 += 5001, x2 += 5001, y2 += 5001;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        Node node = (Node){x1, y1, x2, y2};
        if(x1 == x2) vert.push_back(node);
        if(y1 == y2) hori.push_back(node);
    }
    sort(hori.begin(), hori.end(), cmp_by_y);
    sort(vert.begin(), vert.end(), cmp_by_y);
    LL ans = 0;
    for(int i = 0, sz1 = hori.size(), sz2 = vert.size();i < sz1;i++)
    {
        memset(tree, 0, sizeof(tree));
        for(int i2 = sz1-1, j = sz2-1;i2 > i;i2--)
        {
            while(j >= 0 && vert[j].y2 >= hori[i2].y1)
            {
                if(vert[j].y2 >= hori[i].y1 && vert[j].y1 <= hori[i].y1)
                    add(vert[j].x1);
                j--;
            }
            int l = max(hori[i].x1, hori[i2].x1), r = min(hori[i].x2, hori[i2].x2);
            if(l-1 < r)
            {
                LL num = query(r) - query(l-1);
                ans += (num*(num-1)/2);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
