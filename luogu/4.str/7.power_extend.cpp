#include <cstdio>
void extend(int num)
{
	int first = 0;
	while(num)
	{
		if(first++) putchar('+');
		int i = 0;
		while((1<<(i+1)) <= num) i++;
		num -= (1<<i);
		putchar('2');
		if(i == 0){printf("(0)");return;}
		if(i > 1)
		{
			putchar('(');
			extend(i);
			putchar(')');
		}
	}
}
int main()
{
    int n;
	scanf("%d", &n);
	extend(n);
    return 0;
}
