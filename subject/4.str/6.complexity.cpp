#include <cstdio>
#include <cstring>
#define INF 1000
int vis[30], err, loops, ans, check, vars[150], cnt[150];
int rd_num(char* str)
{
	for(int i = 0, num = 0;;i++)
	{
		if('9' < str[i] || str[i] < '0') return num;
		num *= 10;
		num += (str[i] - '0');
	}
}
void loop(int n, int com)
{
	if(!n){if(loops) err = 1;return;}//illegal1:not match
	char type[2], var[2], str1[5], str2[5];
	scanf("%s", type);
	if(type[0] == 'F') scanf("%s%s%s", var, str1, str2);
	if(err){loop(n-1, 0);return;}
	if(type[0] == 'E')
	{
		if(!loops) err = 1;
		loops--;
		vis[vars[loops]] = 0;
		if(loops <= check) check = INF;
		if(loops <= check && com > ans) ans = com;
		loop(n-1, com-cnt[loops]);
		return;
	}
	if(type[0] == 'F')
	{
		if(vis[var[0]-'a']) err = 1;//illegal2:var name
		vis[var[0]-'a'] = 1;
		vars[loops] = var[0]-'a';
		int begin = INF, end = INF;//INF for n
		if('0' <= str1[0] && str1[0] <= '9')
			begin = rd_num(str1);
		if('0' <= str2[0] && str2[0] <= '9')
			end = rd_num(str2);
		if(begin > end) check = loops;//just check downwards
		if(loops <= check && begin < end && end == INF) cnt[loops] = 1;
		else cnt[loops] = 0;
		loops++;
		loop(n-1, com+cnt[loops-1]);
	}
}
int main()
{
    int t, n, com;
	char str[150], aim[2];
	strcpy(aim, "^");
	scanf("%d", &t);
    while(t--)
	{
		scanf("%d%s", &n, str);
		if(!strstr(str, aim)) com = 0;
		else com = rd_num(strstr(str, aim)+1);
		memset(vis, 0, sizeof(vis));
		ans = err = loops = 0, check = INF;
		if(n & 1) err = 1;
		loop(n, 0);
		if(err) printf("ERR\n");
		else printf("%s\n", ans == com ? "Yes" : "No");
	}
    return 0;
}
