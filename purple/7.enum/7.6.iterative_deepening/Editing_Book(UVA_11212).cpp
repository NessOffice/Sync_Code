#include <cstdio>
#include <cstring>
const int maxn = 9 + 1;
int n, str[maxn];
int get_mis(int* str)
{
	int mis = 0;
	for(int i = 1;i < n;i++)
		if(str[i] != str[i-1] + 1) mis++;
	if(str[n-1] != n) mis++;
	return mis;
}
bool dfs(int d, int maxd, int mis)
{
	if(d == maxd) return mis == 0;
	if(mis > 3*(maxd - d)) return false;
	int origin[maxn];
	memcpy(origin, str, sizeof(str));
	for(int begin = 0;begin < n;begin++)
	for(int end = begin + 1;end <= n;end++)
	for(int pos = 0;pos < begin;pos++)//不必考虑 pos > end 的情况
	{
		int len = end - begin;
		for(int i = pos;i < pos + len;i++) str[i] = origin[i - pos + begin];
		for(int i = pos + len;i < end;i++) str[i] = origin[i - len];
		int newmis = get_mis(str);
		if(dfs(d + 1, maxd, newmis)) return true;
		memcpy(str, origin, sizeof(str));
	}
	return false;
}
int main()
{
	//  freopen("in.txt","r",stdin);
	//  freopen("out.txt","w",stdout);
	int kase = 0;
	bool done;
	while(scanf("%d", &n), n)
	{
		done = false;
		for(int i = 0;i < n;i++)
			scanf("%d", &str[i]);
		int mis = get_mis(str);
		for(int maxd = 0;!done;maxd++)
		if(done = dfs(0, maxd, mis))
			printf("Case %d: %d\n", ++kase, maxd);
	}
	return 0;
}
