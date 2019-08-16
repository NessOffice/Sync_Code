#include <cstdio>
int main()
{
	int n, a[505][505], ans = 0, maxv;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		maxv = 0;
		for(int j = 1;j < i;j++)
			a[i][j] = a[j][i];
		for(int j = 1;j <= n;j++)
		{
			if(j == i) continue;
			if(j > i) scanf("%d", &a[i][j]);
			if(a[i][j] > maxv)
				maxv = a[i][j];
		}
		for(int j = 1;j <= n;j++)
		{
			if(j == i) continue;
			if(ans > maxv) break;
			if(a[i][j] > ans && maxv > a[i][j])
				ans = a[i][j];
		}
	}
	printf("1\n%d\n", ans);
	return 0;
}
