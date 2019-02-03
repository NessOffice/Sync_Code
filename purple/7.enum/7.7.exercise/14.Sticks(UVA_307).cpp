#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int n, d, sum, pieces[maxn], vis[maxn];
int watcher = 0;
int find_max(int num)
{
	int i = n - 1;
	for(;i >= 0;i--)
	if(pieces[i] <= num && !vis[i])
		break;
	return i;
}
bool paste(int len)
{
	if(len == 0) return true;
	for(int i = find_max(len);i >= 0;i--)
	{
		if(watcher) printf("%d\n", i);
		if(vis[i]) continue;
		vis[i] = 1;
		if(paste(len - pieces[i])) return true;
		vis[i] = 0;
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
			scanf("%d", &pieces[i]);
			sum += pieces[i];
		}
		sort(pieces, pieces + n);
		for(d = pieces[n-1];d < sum;d++)
		{
			if(sum % d) continue;
			if(d == 89) watcher = 1;
			else watcher = 0;
			int cnt = sum / d, flag = 1;
			memset(vis, 0, sizeof(vis));
			for(int i = 0;i < cnt && flag;i++)
				if(!paste(d)) flag = 0;
			if(flag) break;
		}
		printf("%d\n", d);
	}
	return 0;
}
