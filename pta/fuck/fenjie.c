#include <stdio.h>
int n, fj[200], mark = 4;
void print(int d)
{
	int i;
	printf("%d", n);
	for(i = 0;i < d;i++)
	{
		putchar(i ? '+' : '=');
		printf("%d", fj[i]);
	}
}
void do_mark()
{
	if(mark != 4)
		putchar(mark ? ';' : '\n');
	mark = (mark ? mark-1 : 3);
}
void dfs(int m, int last, int d)
{
	int i = last;
	if(m == 0)
	{
		do_mark();
		print(d);
	}
	if(m < last) return;
	for(i;i <= m;i++)
	{
		fj[d] = i;
		dfs(m-i, i, d+1);
	}
}
int main()
{
    scanf("%d", &n);
	dfs(n, 1, 0);
    return 0;
}
