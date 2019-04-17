#include<stdio.h>
#include<string.h>
int main()
{
	//bloody lesson
	char temp[1500];
	char origin[10000], link[10000], split;
	char res[1002][1002];
	scanf("%[^\n]\n", origin);
	scanf("%c", &split);
	getchar();
	scanf("%[^\n]", link);
	int len = 0, last = 0, num = 0;
	char* ptr = origin;
	while(*ptr)
	{
		if(*ptr == split){
			res[num++][len] = '\0';
			len = 0;
		}else
			res[num][len++] = *ptr;
		ptr++;
	}
	res[num++][len] = '\0';
	int i;
	putchar('[');
	for(i = 0;i < num;i++)
	{
		if(i) printf(", ");
		printf("\"%s\"", res[i]);
	}
	putchar(']');
	putchar('\n');
	for(i = 0;i < num;i++)
	{
		if(i) printf("%s", link);
		printf("%s", res[i]);
	}
	printf("\n");
    return 0;
}