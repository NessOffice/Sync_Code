#include <cstdio>
int main()
{
	int n, last = -1, coin, ok = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &coin);
		if(!ok && !coin)
		{
			if(last == -1 && (i&1)) ok = 1;
			else last = i;
		}
	}
	if(!ok && ((n-last+1)&1)) ok = 1;
	printf("%s\n", ok ? "YES" : "NO");
	return 0;
}
