#include <stdio.h>
#include <string.h>
int main()
{
	char s1[1000], s2[1000], temp[1000];
	fgets(s1, 1000, stdin);
	fgets(s2, 1000, stdin);
	int len1 = strlen(s1), len2 = strlen(s2);
	s1[len1-1] = '\0', s2[len2-1] = '\0';
	while(strstr(s1, s2))
	{
		len2 = strlen(s2);
		int offset = strstr(s1, s2) - s1;
		strcpy(temp, s1);
		strcpy(s1+offset, temp+offset+len2);
	}
	printf("%s", s1);
	return 0;
}