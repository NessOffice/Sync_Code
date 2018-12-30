#include <stdio.h>
int main()
{
	int T, M, x, y, r[5], num[5];
	scanf("%d", &T);
	while(T--)
	{
		num[1] = num[2] = num[3] = 1;
		r[1] = 1, r[2] = r[3] = 0;
		scanf("%d", &M);
		while(M--)
		{
			scanf("%d %d", &x, &y);
			num[x]--, num[y]++;
			r[y] |= r[x];
			if(num[x] == 0) r[x] = 0;
		}
		for(int i = 1;i <= 3;i++)
			if(r[i]) printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}
