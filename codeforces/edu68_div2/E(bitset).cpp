#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>
typedef long long LL;
const int maxn = 5e5 + 5;
using namespace std;
struct Node{int x1, y1, x2, y2;};
bool intersect(Node lhs, Node rhs)
{
    if(lhs.x1 == lhs.x2)
        return (lhs.y1 <= rhs.y1 && rhs.y1 <= lhs.y2) && (rhs.x1 <= lhs.x1 && lhs.x1 <= rhs.x2);
    if(lhs.y1 == lhs.y2)
        return (lhs.x1 <= rhs.x1 && rhs.x1 <= lhs.x2) && (rhs.y1 <= lhs.y1 && lhs.y1 <= rhs.y2);
}
vector<Node> hori, vert;
bitset<5000> st[5000];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        Node node = {x1, y1, x2, y2};
        if(x1 == x2) vert.push_back(node);
        if(y1 == y2) hori.push_back(node);
    }
    LL ans = 0;
    if(vert.size() > hori.size()) swap(vert, hori); // ???
    for(int i = 0, sz1 = vert.size();i < sz1;i++)
    {
        for(int j = 0, sz2 = hori.size();j < sz2;j++)
            if(intersect(vert[i], hori[j])) st[i][j] = true;
        for(int i2 = 0;i2 < i;i2++)
        {
            LL num = (st[i]&st[i2]).count();
            ans += (num*(num-1)/2);
        }
    }
    printf("%lld", ans);
    return 0;
}
