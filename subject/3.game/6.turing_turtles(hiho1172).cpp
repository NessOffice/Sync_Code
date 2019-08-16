#include <cstdio>
int main()
{
	int n, ans = 0;
	char state;
	scanf("%d\n", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%c", &state);
		if(state == 'H') ans ^= i;
	}
	printf("%s", ans ? "Alice" : "Bob");
	return 0;
}
