#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int sum[maxn];
tr1::unordered_map<LL, int>qmap;
LL convert(int l, int r){return 1LL*l*maxn + r;}
int query(int l, int r)
{
    if(l == r) return 0;
    if(qmap[convert(l, r)]) return qmap[convert(l, r)];
    int mid = (l + r) / 2;
    int add = (10+sum[r]-sum[mid]) % 10;
    add += ((10+sum[mid]-sum[l-1]) % 10);
    add /= 10;
    return qmap[convert(l, r)] = add + query(l, mid) + query(mid+1, r);
}
int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", sum + i);
        sum[i] = (sum[i] + sum[i-1]) % 10;
    }
    scanf("%d", &q);
    while(q--)
    {
        int l, r, mid;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
