#include <cstdio>
int main()
{
	int cnt = 0, n, m, vis[110], i = 0;
	scanf("%d%d", &n, &m);
	for(int j = 0;j < n;j++) vis[j] = 0;
	while(cnt < n)
	{
		for(int j = 0;j < m;j++)
		{
			i = (i+1) % n;
			while(vis[i]) i = (i+1) % n;
		}
		if(cnt++) putchar(' ');
		printf("%d", i ? i : n);
		vis[i] = 1;
	}
	return 0;
}
