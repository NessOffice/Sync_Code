#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
LL a[maxn], n;
map<pair<LL, LL>, LL> G, dis;
vector<LL> mark, points;
void add_edge(LL u, LL v){G[make_pair(u, v)] = G[make_pair(v, u)] = 1;}
LL floyd() // return the size of the minimum cycle
{
    LL sz = points.size(), ans = maxn;
    sort(points.begin(), points.end());
    for(LL i = 0;i < sz;i++)
    for(LL j = 0;j < sz;j++)
    {
        dis[make_pair(points[i], points[j])] = dis[make_pair(points[j], points[i])] = (points[i] == points[j] ? 0 : maxn);
        if(G[make_pair(points[i], points[j])]) dis[make_pair(points[i], points[j])] = dis[make_pair(points[j], points[i])] = dis[make_pair(points[j], points[i])] = 1;
    }
    for(LL k = 0;k < sz;k++)
    {
        for(LL i = 0;i < k;i++)
        for(LL j = i+1;j < k;j++)
        {
            if(points[i] == points[k]) continue;
            if(points[j] == points[k]) continue;
            if(points[i] == points[j]) continue; // caution
            // if(!G[make_pair(points[i], points[j])]) continue;
            if(G[make_pair(points[i], points[k])])
            if(G[make_pair(points[j], points[k])])
                ans = min(ans, dis[make_pair(points[i], points[j])] + 2);
        }
        for(LL i = 0;i < sz;i++)
        for(LL j = 0;j < sz;j++)
            dis[make_pair(points[i], points[j])] = min(dis[make_pair(points[i], points[j])], dis[make_pair(points[i], points[k])] + dis[make_pair(points[j], points[k])]);
    }
    return ans;
}
LL solve()
{
    for(LL i = 0;i <= 62;i++)
    {
        mark.clear();
        LL mask = 1LL << i; // caution
        for(LL j = 0;j < n;j++)
            if(a[j] & mask) mark.push_back(j);
        if(mark.size() >= 3) return 3;
        if(mark.size() == 2)
        {
            points.push_back(mark[0]);
            points.push_back(mark[1]);
            add_edge(mark[0], mark[1]);
            add_edge(mark[1], mark[0]);
        }
    }
    LL ans = floyd();
    return (ans == maxn ? -1 : ans);
}
int main()
{
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++)
        scanf("%lld", a + i);
    printf("%lld", solve());
    return 0;
}