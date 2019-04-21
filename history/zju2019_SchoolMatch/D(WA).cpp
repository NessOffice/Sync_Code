#include <cstdio>
int main()
{
	char ans[243];
	for(int i = 0;i < 81;i++)
	{
		if(i % 3 == 2) ans[i] = 'R';
		else if(i % 27 >= 18) ans[i] = 'D';
		else if(i % 9 >= 6) ans[i] = 'L';
		else ans[i] = 'U';
	}
	for(int i = 81;i < 2*81;i++)
		ans[i] = 'I';
	for(int i = 2*81;i < 243;i++)
		ans[i] = 'P';
	printf("%s", ans);
	return 0;
}
