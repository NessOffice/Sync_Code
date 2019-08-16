#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
struct Node{int cmd, id, x;}nodes[maxn];
int ans[maxn], ok[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", ans + i);
    int q;
    scanf("%d", &q);
    for(int i = 1;i <= q;i++)
    {
        scanf("%d", &nodes[i].cmd);
        if(nodes[i].cmd == 1) scanf("%d%d", &nodes[i].id, &nodes[i].x);
        if(nodes[i].cmd == 2) scanf("%d", &nodes[i].x);
    }
    int x = 0;
    for(int i = q;i >= 1;i--)
    {
        if(nodes[i].cmd == 1){
            if(ok[nodes[i].id]) continue;
            ans[nodes[i].id] = max(nodes[i].x, x);
            ok[nodes[i].id] = 1;
        }else
            x = max(x, nodes[i].x);
    }
    for(int i = 1;i <= n;i++)
    {
        if(!ok[i]) ans[i] = max(x, ans[i]);
        printf("%d ", ans[i]);
    }
    return 0;
}
