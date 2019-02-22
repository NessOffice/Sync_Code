#include <cstdio>
#include <algorithm>
const int maxn = 100000 + 10;
struct s{int id, val;}a[maxn];
bool cmp(s& lhs, s& rhs){return lhs.val > rhs.val;}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("o1.txt", "w", stdout);
	int n, ans[maxn];
	while(~scanf("%d", &n))
	{
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &a[i].val);
			sum += a[i].val;
			a[i].id = i;
		}
		if(sum & 1){printf("No\n");continue;}
		sum >>= 1;
		std::sort(a, a + n, cmp);
		for(int i = 0;i < n;i++) ans[i] = -1;
		for(int i = 0;i < n && sum;i++)
			if(a[i].val <= sum)
			{
				sum -= a[i].val;
				ans[a[i].id] = 1;
			}
		printf("Yes\n%d", ans[0]);
		for(int i = 1;i < n;i++) printf(" %d", ans[i]);
		putchar('\n');
	}
	return 0;
}
