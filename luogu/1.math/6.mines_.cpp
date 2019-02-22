#include <cstdio>
#include <cstring>
int n, ms[10010], num[10010];//ms for mines
int judge(int i){return (ms[i+1] == 0 || ms[i+1] == 1) && (num[i] == ms[i-1]+ms[i]+ms[i+1]);}
int dfs(int i)
{
	if(i > n) return 1;//special:n == 1
	if(ms[i] < 0)
	{
		int ans = 0;
		for(int j = 0;j < 2;j++)
		{
			if(ms[i+1] >= 0)
				ms[i] = j;
			if(ms[i+1] < 0)
				ms[i+1] = num[i] - ms[i-1] - j,
				ms[i] = j;
			if(judge(i))
				ans += dfs(i+1);
		}
		return ans;
	}
	if(ms[i+1] < 0)
		ms[i+1] = num[i] - ms[i-1] - ms[i];
	if(judge(i))
		return dfs(i+1);
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &num[i]);
	memset(ms, -1, sizeof(ms));
	ms[0] = ms[n+1] = 0;
	for(int i = 1;i < n;i += 3)
	{
		if(ms[i+2] >= 0) break;
		ms[i+2] = num[i+1] - num[i] + ms[i-1];
	}
	for(int i = n;i > 1;i -= 3)
	{
		if(ms[i-2] >= 0) break;
		ms[i-2] = ms[i+1] - num[i] + num[i-1];
	}
	printf("%d", dfs(1));
	return 0;
}
