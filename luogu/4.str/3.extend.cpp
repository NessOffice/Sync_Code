#include <cstdio>
#include <cstring>
char str[110];
int type, rep, rev, offset;
int judge(int i)
{
	if('a' <= str[i-1] && str[i+1] <= 'z' && str[i+1] > str[i-1])
		{offset = (type == 2 ? 'A' - 'a' : 0);return 1;}
	if('0' <= str[i-1] && str[i+1] <= '9' && str[i+1] > str[i-1])
		{offset = 0;return 2;}
	return 0; 
}
void fill(int begin, int end)
{
	if(rev == 2){int t = begin;begin = end;end = t;}
	int d = (rev == 2 ? -1 : 1);
	for(int j = begin+d;j != end;j += d)//caution: rev && begin
	{
		char temp = (type == 3 ? '*' : j+offset);
		for(int k = 0;k < rep;k++)
			putchar(temp);
	}
}
int main()
{
	scanf("%d%d%d", &type, &rep, &rev);
	scanf("%s", str);
	for(int i = 0, len = strlen(str);i < len;i++)
	{
		if(i && i+1 < len && str[i] == '-' && judge(i))
			fill(str[i-1], str[i+1]);
		else putchar(str[i]);
	}
	return 0;
}
