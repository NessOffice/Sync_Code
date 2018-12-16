#include <cstdio>
const int maxn = 1<<10;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, m, level[10], kase = 0;
	char tree[maxn], var[4], query[maxn];
	while(scanf("%d", &n) && n)
	{
		printf("S-Tree #%d:\n", ++kase);
		for(int i = 0;i < n;i++)
		{
			scanf("%s", var);
			level[i] = var[1] - '0' - 1;
		}
		scanf("%s", tree); 
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s", query);
			int index = 0;
			for(int i = 0;i < n;i++)
			{
				if(query[level[i]] == '0') index *= 2;
				else index = 2 * index + 1;
			}
			printf("%c", tree[index]);
		}
		printf("\n\n");
	}
	return 0;
}
