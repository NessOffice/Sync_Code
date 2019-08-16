#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int n, ans, sum = 0, a[maxn], vis[maxn];
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
	scanf("%d", &n);
	int temp, n1 = 0;
	while(n--)
	{
		scanf("%d", &temp);
		if(temp <= 50)
			a[n1++] = temp,
			sum += temp;
	}
	n = n1;
	sort(a, a + n, cmp);
	for(int cnt = n;cnt > 0;cnt--)
	{
		ans = sum / cnt;
		if(sum % cnt || ans < a[0]) continue;
		memset(vis, 0, sizeof(vis));
		if(dfs(cnt, 0, ans)) break;
	}
	printf("%d\n", ans);
	return 0;
}
