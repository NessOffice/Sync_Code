#include <cstdio>
char ans[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	int n;
	while(~scanf("%d", &n))
	{
		printf("2 %d %d\n", n, n);
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
				putchar(ans[j]);
			putchar('\n');
		}
		putchar('\n');
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
				putchar(ans[i]);
			putchar('\n');
		}
	}
	return 0;
}
