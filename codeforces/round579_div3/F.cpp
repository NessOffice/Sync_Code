
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1.5e5+5;
struct Operation{int a, b;}op_plus[105], op_minus[105];
bool cmp_by_a(const Operation &lhs, const Operation &rhs){return lhs.a < rhs.a;}
bool cmp_by_b(const Operation &lhs, const Operation &rhs){return lhs.b > rhs.b;}
int main()
{
    int n, r, cnt1 = 0, cnt2 = 0;
    scanf("%d%d", &n, &r);
    for(int i = 1;i <= n;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(b >= 0) op_plus[cnt1++] = Operation{a, b};
        else op_minus[cnt2++] = Operation{a, b};
    }
    sort(op_plus, op_plus + cnt1, cmp_by_a);
    bool ok = true;
    for(int i = 0;i < cnt1 && ok;i++)
    {
        if(r < op_plus[i].a)
            ok = false;
        r += op_plus[i].b;
    }
    sort(op_minus, op_minus + cnt2, cmp_by_b);
    for(int i = 0;i < cnt2 && ok;i++)
    {
        for(int j = i;j < cnt2 && ok;j++)
        {
            if(r < op_minus[j].a)
                ok = false;
        }
        r += op_minus[i].b;
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
