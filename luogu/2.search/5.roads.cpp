#include <cstdio>
#include <algorithm>
const int maxn = 1e5+7;
struct Road{int u, v, t;}roads[maxn];
bool cmp(const Road& lhs, const Road& rhs){return lhs.t < rhs.t;}
int pre[maxn], num[maxn];
int find(int u)
{
    int v = u;
    while(v != pre[v])
        v = pre[v];
    return pre[u] = v;
}
void join(int u, int v)
{
    int fu = find(u), fv = find(v);
    if(fu == fv) return;
    num[fv] += num[fu];
    pre[fu] = fv;
}
int main()
{
    int n, m, u, v, t = -1;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
        pre[i] = i, num[i] = 1;
    for(int j = 0;j < m;j++)
        scanf("%d%d%d", &roads[j].u, &roads[j].v, &roads[j].t);
    std::sort(roads, roads + m, cmp);
    for(int j = 0;j < m && t == -1;j++)
    {
        u = roads[j].u,
        v = roads[j].v;
        join(u, v);
        if(num[find(u)] == n)
            t = roads[j].t;
    }
    printf("%d", t);
	return 0;
}
