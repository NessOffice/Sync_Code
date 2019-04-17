#include <stdio.h>
#include <string.h>
int main()
{
	char temp[300];
	char str[300][300];
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++)
		scanf("%s", str[i]);
	for(int i = 0;i < k;i++)
	{
		for(int j = 0;j < n-i-1;j++)
		{
			if(strcmp(str[j], str[j+1]) >= 0)
			{
				strcpy(temp, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], temp);
			}
		}
	}
	for(int i = 0;i < n;i++)
		printf("%s\n", str[i]);
	return 0;
}