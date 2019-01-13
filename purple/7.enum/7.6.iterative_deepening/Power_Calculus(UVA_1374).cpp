#include <cstdio>
int n, p[20];
int max(int a, int b){return a > b ? a : b;}
bool dfs(int d, int maxd, int maxv)
{
	if(p[d] == n) return true;
	if(d == maxd) return false;
	if(maxv << (maxd - d) < n) return false;
	for(int i = 0;i <= d;i++)
	{
		p[d+1] = p[d] + p[i];
		if(dfs(d+1, maxd, max(maxv, p[d+1]))) return true;
		p[d+1] = p[d] - p[i];
		if(dfs(d+1, maxd, max(maxv, p[d+1]))) return true;
	}
	return false;
}
int main()
{
	//  freopen("in.txt","r",stdin);
	//  freopen("out.txt","w",stdout);
	bool done;
	while(scanf("%d", &n), n)
	{
		done = false;
		p[0] = 1;
		for(int maxd = 0;!done;maxd++)
		if(dfs(0, maxd, p[0]))
			printf("%d\n", maxd), done = true;
	}
	return 0;
}
