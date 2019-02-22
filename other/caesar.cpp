#include <cstdio>
#include <cstring>
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char str[10000];
	scanf("%s", str);
	int len = strlen(str);
	for(int offset = 0;offset < 26;offset++)
	{
		for(int i = 0;i < len;i++)
		{
			if('A' <= str[i] && str[i] <= 'Z')
			{
				str[i] -= 'A';
				str[i] = (str[i] + offset) % 26 + 'A';
			}
			if('a' <= str[i] && str[i] <= 'z')
			{
				str[i] -= 'a';
				str[i] = (str[i] + offset) % 26 + 'a';
			}
			putchar(str[i]);
		}
		printf("\n\n");
	}
	return 0;
}
