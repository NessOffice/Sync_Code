#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pr;
const int maxn = 5e5+5;
int l[maxn], r[maxn], mark[maxn];
LL val[maxn];
struct cmp{bool operator()(const pr lhs, const pr rhs){return lhs.second < rhs.second;}};
int main()
{
	priority_queue<pr, vector<pr>, cmp> q;
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++)
	{
        scanf("%lld", val + i);
        q.push(make_pair(i, val[i]));
        l[i] = i-1;
        r[i] = i+1;
	}
    LL ans = 0;
	while(k--)
	{
		while(mark[q.top().first]) q.pop();
        int i = q.top().first;
        if(val[i] < 0) break;
        ans += val[i];
        q.pop();
        val[i] = val[l[i]] + val[r[i]] - val[i];
        mark[l[i]] = mark[r[i]] = 1;
        l[i] = l[l[i]], r[i] = r[r[i]];
        r[l[i]] = l[r[i]] = i;
        q.push(make_pair(i, val[i]));
	}
    printf("%lld", ans);
	return 0;
}
