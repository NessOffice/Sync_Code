#include <cstdio>
const int maxn = 100 + 10;
int main()
{
	int T, ans, diff[4];
	char s[2][maxn];
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%s%s", s[0], s[1]);
		ans = 0;
		for(int i = 0;i < 4;i++) diff[i] = 0;//diff: the key point of this problem
		for(int i = 0;s[0][i] != '\0';i++)
		{
			if(s[0][i] == '?') diff[2 + s[1][i]-'0']++;
			else if(s[0][i] != s[1][i]) diff[s[0][i]-'0']++;
		}
		if(diff[1] > diff[0] + diff[3]) ans = -1;
		if(ans == 0)
		{
			ans += (diff[2] + diff[3]);
			ans += (diff[0] > diff[1] ? diff[0] : diff[1]);
		}
		printf("Case %d: %d\n", kase, ans);
	}
	return 0;
}
