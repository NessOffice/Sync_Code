#include <stdio.h>
#include <string.h>
#define MAXS 150 + 5
char str[MAXS][MAXS];
int cmp(char* s1, char* s2)
{
	if(strlen(s1) != strlen(s2)) return strlen(s1) > strlen(s2);
	else return strcmp(s1, s2) > 0;
}
int main()
{
    int n, maxv = -1;
	scanf("%d", &n);
    for(int i = 0;i < n;i++)
	{
		scanf("%s", str[i]);
		if(maxv < 0 || cmp(str[i], str[maxv]))
			maxv = i;
	}
	printf("%d\n%s\n", maxv+1, str[maxv]);
    return 0;
}
