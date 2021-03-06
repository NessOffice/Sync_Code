#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int n, ans, sum, a[maxn], vis[maxn];
bool cmp(const int& lhs, const int& rhs){return lhs > rhs;}
bool dfs(int cnt, int pos, int rest)
{
	if(!cnt) return true;
	for(int i = pos;i < n;i++)
	{
		if(vis[i]) continue;
		if(rest == a[i])
		{
			vis[i] = 1;
			if(dfs(cnt-1, 0, ans))
				return true;
			vis[i] = 0;
			return false;//cutting 1
		}
		else if(rest > a[i])
		{
			vis[i] = 1;
			if(dfs(cnt, i+1, rest-a[i]))
				return true;
			vis[i] = 0;
			while(i+1 < n && a[i] == a[i+1]) i++;//cutting 2
		}
		if(rest == ans)//cutting 1
			return false;
	}
	return false;
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	while(sum = 0, scanf("%d", &n), n)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n, cmp);
		for(int cnt = n;cnt > 0;cnt--)
		{
			ans = sum / cnt;
			if(sum % cnt || ans < a[0]) continue;
			memset(vis, 0, sizeof(vis));
			if(dfs(cnt, 0, ans)) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
