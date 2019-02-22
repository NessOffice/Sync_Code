#include <cstdio>
const int maxn = 100000 + 10;
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int N, D;
	char s[maxn], ans[maxn];
	while(scanf("%d%d", &N, &D) && N)
	{
		scanf("%s", s);
		int t = 0;
		for(int i = 0;i < N;i++)
		{
			while(t && i <= D + t-1 && s[i] > ans[t-1]) t--;
			if(t < N-D) ans[t++] = s[i];
		}
		for(int i = 0;i < N-D;i++) putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}
