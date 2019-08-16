#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
struct Node{int x, y;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.y > rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x);}
map<int, int> set_of_x;
int x_unique[maxn], n, n_unique;
int tree[maxn<<1];
int lowbit(int num){return num&(-num);}
void add(int begin)
{
    for(int i = begin;i <= n_unique;i += lowbit(i))
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
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
        x_unique[i] = nodes[i].x;
    }
    sort(x_unique+1, x_unique+n+1);
    n_unique = unique(x_unique+1, x_unique+n+1)-x_unique-1;
    sort(nodes+1, nodes+n+1, cmp);
    int sz = 0, sz_lst = 0;
    LL ans = 0;
    for(int l = 1, r;l <= n;l = r)
    {
        int x_lst = 0, x_now;
        r = l;
        while(r <= n && nodes[r].y == nodes[l].y)
        {
            x_now = lower_bound(x_unique+1, x_unique+n_unique+1, nodes[r].x) - x_unique;
            if(!set_of_x.count(x_now))
            {
                set_of_x[x_now] = 1;
                add(x_now);
                sz++;
            }
            sz_lst = query(x_now-1) - query(x_lst); // x_now-1, not x_now
            ans -= (1LL*sz_lst*(sz_lst+1)/2); // sz_lst for the number of points between x_p1 and x_p2
            x_lst = x_now;
            r++;
        }
        x_now = n_unique;
        sz_lst = query(x_now) - query(x_lst); // don't forget this term
        ans -= (1LL*sz_lst*(sz_lst+1)/2);
        ans += (1LL*sz*(sz+1)/2);
    }
    printf("%lld", ans);
    return 0;
}
/*
3
1 1
1 2
1 3

3
1 1
2 1
3 1

4
2 1
2 2
3 1
3 2

5
3 6
5 10
4 3
2 1
1 3
*/