#include <stdio.h>
#include <string.h>
int main()
{
	freopen("in.txt", "r", stdin);
	char s[10000];
	while(~scanf("%s", s))
	{
		int len = strlen(s), i = 0, temp;
		while(i < len)
		{
			temp = 0;
			if(s[i] != 'A' && s[i] != 'F'){putchar(s[i]), i++;}
			else
			{
				for(int j = 0;j < 5;j++)
				{
					temp *= 2;
					if(s[i+j] == 'F') temp++;
				}
				putchar(temp+'a');
				i += 5;
			}
		}
		putchar(' ');
	}
	return 0;
}
