#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 6e5+5;
int color[maxn];
int cnt, head[maxn], nxt[maxn], to[maxn];
int sz1, sz2, sz3, n, m;
void add_edge(int u, int v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
bool check()
{
    if(sz2 == 0 || sz3 == 0) return false;
    if((LL)m != 1LL*sz1*sz2+1LL*sz2*sz3+1LL*sz1*sz3) return false;
    for(int u = 1;u <= n;u++)
        for(int i = head[u];i;i = nxt[i])
            if(color[to[i]] == color[u])
                return false;
    return true;
}
int main()
{
    sz1 = sz2 = sz3 = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    int u1 = 1, u2 = -1;
    for(int u = 1;u <= n;u++)
        color[u] = 1;
    sz1 = n;
    for(int i = head[u1];i;i = nxt[i])
    {
        if(u2 == -1) u2 = to[i];
        color[to[i]] = 2;
        sz1--, sz2++;
    }
    for(int i = head[u2];i;i = nxt[i])
        if(color[to[i]] == 2)
        {
            color[to[i]] = 3;
            sz2--, sz3++;
        }
    if(check()){
        for(int u = 1;u <= n;u++)
            printf("%d ", color[u]);
    }else
        printf("-1");
    return 0;
}
