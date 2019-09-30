#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
struct Node{LL a, b;}nodes[maxn];
bool cmp(const Node &lhs, const Node &rhs){return lhs.a * rhs.b < lhs.b < rhs.a || (lhs.a * rhs.b == lhs.b < rhs.a && lhs.b < rhs.b);}
int main()
{
    LL T;
    scanf("%lld", &T);
    for(LL kase = 1;kase <= T;kase++)
    {
        LL n;
        scanf("%lld", &n);
        for(LL i = 0;i < n;i++)
        {
            LL HP, ATK;
            scanf("%lld%lld", &HP, &ATK);
            LL hp = sqrt(2*HP)+1;
            if(hp*(hp-1) >= 2*HP) hp--;
            nodes[i].a = hp;
            nodes[i].b = ATK;
        }
        sort(nodes, nodes + n, cmp);
        LL ans = 0, sum = 0;
        for(LL i = 0;i < n;i++)
        {
            sum += nodes[i].a;
            ans += sum * nodes[i].b;
        }
        printf("Case #%lld: %lld\n", kase, ans);
    }
    return 0;
}
