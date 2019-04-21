#include <cstdio>
typedef long long LL;
const LL maxn = 2000 + 10;
LL t[maxn][maxn], vis[maxn][maxn];
int main()
{
	LL T;
	scanf("%lld", &T);
	while(T--)
	{
		LL n, m, a, b, k, ans = 0;
		char s[maxn];
		scanf("%lld%lld", &n, &m);
		scanf("%lld%lld%lld", &a, &b, &k);
		scanf("%s", s);
		for(LL i = 1;i <= n;i++)
		for(LL j = 1;j <= m;j++)
		{
			scanf("%1lld", &t[i][j]);
			vis[i][j] = -1;
		}

		while(k--)
		{
			LL x = 81*t[a][b] + 27*t[a-1][b] + 9*t[a+1][b] + 3*t[a][b-1] + t[a][b+1];
			char cmd = s[x];
			if(vis[a][b] == ans) break;
			vis[a][b] = ans;
			switch(cmd)
			{
				case 'U':
					if(t[a-1][b] != 1)
						a--;
					break;
				case 'D':
					if(t[a+1][b] != 1)
						a++;
					break;
				case 'L':
					if(t[a][b-1] != 1)
						b--;
					break;
				case 'R':
					if(t[a][b+1] != 1)
						b++;
					break;
				case 'P':
					if(t[a][b] == 2)
						t[a][b] = 0,
						ans++;
					break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
