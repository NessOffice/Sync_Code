#include <cstdio>
#include <cstring>
typedef long long LL;
const LL maxn = 1e7 + 5;
struct Node{LL x, y, z, f, pos;}nodes[maxn];
LL dist(LL i, LL j)
{
    LL x1 = nodes[i].x, y1 = nodes[i].y, z1 = nodes[i].z;
    LL x2 = nodes[j].x, y2 = nodes[j].y, z2 = nodes[j].z;
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}
LL find(LL u)
{
    LL v = u;
    while(v != nodes[v].f)
        v = nodes[v].f;
    return nodes[u].f = v;
}
bool join(LL u, LL v)
{
    LL fu = find(u), fv = find(v);
    LL &pos1 = nodes[fu].pos, &pos2 = nodes[fv].pos;
    if(pos1 || pos2)
    {
        if(pos1 && pos2 && pos1 != pos2)
            return true;
        if(pos1) pos2 = pos1;
        if(pos2) pos1 = pos2;
    }
    nodes[fu].f = fv;
    return false;
}
int main()
{
    LL T, n, h, r, ok;
    scanf("%lld", &T);
    while(T--)
    {
        ok = 0;
        scanf("%lld%lld%lld", &n, &h, &r);
        for(LL i = 0;i < n;i++)
        {
            nodes[i].f = i;
            nodes[i].pos = 0;
            scanf("%lld%lld%lld", &nodes[i].x, &nodes[i].y, &nodes[i].z);
            if(ok) continue;
            if(nodes[i].z <= r) nodes[i].pos = 1;
            if(nodes[i].z + r >= h)
            {
                if(nodes[i].pos) ok = 1;
                else nodes[i].pos = 2;
            }
            for(LL j = 0;j < i;j++)
                if(dist(i, j) <= 4*r*r && join(i, j)) ok = 1;
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
	return 0;
}
