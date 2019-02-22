#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 800000 + 10;
struct Node{int q, d;}a[maxn];
bool cmp(Node& lhs, Node& rhs){return lhs.d < rhs.d;}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d%d", &a[i].q, &a[i].d);
		priority_queue<int> q;
		int t = 0, ans = 0;
		sort(a, a+n, cmp);
		for(int i = 0;i < n;i++)
		{
			if(t + a[i].q <= a[i].d)
				q.push(a[i].q),
				t += a[i].q,
				ans++;
			else if(!q.empty() && q.top() > a[i].q)
				t = t - q.top() + a[i].q,
				q.pop(), q.push(a[i].q);
		}
		printf("%d\n", ans);
		if(T) putchar('\n');
	}
	return 0;
}
