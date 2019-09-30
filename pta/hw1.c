#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */

#include <math.h>
#define EPS 1e-8;
int eq(ElementType x, ElementType y){return fabs(x-y) < EPS;}

#include <string.h>
ElementType EvalPostfix( char *expr )
{
	ElementType st[Max_Expr], num, num1, num2;
	int i, j, k, debug, flag;
	int ptr = 0, len = strlen(expr);
	for(i = 0;i < len;i++)
	{
		if(expr[i] == ' ') continue;
//		printf("[DEBUG]");
//		for(debug = 0;debug < ptr;debug++)
//			printf("%lf ", st[debug]);
//		printf("\n");
//		printf("[DEBUG]i: %d\n", i);
		if((expr[i] >= '0' && expr[i] <= '9') || (expr[i] == '-' && expr[i] != len-1 && (expr[i+1] >= '0' && expr[i+1] <= '9')))
		{
			num = 0;
			if(expr[i]=='-')
				flag = -1, j = i+1;
			else
				flag = 1, j = i;
			while(expr[j] >= '0' && expr[j] <= '9')
			{
				num = num * 10 + expr[j] - '0';
				j++;
			}
			if(expr[j]=='.')
			{
				j++;
				while(expr[j] >= '0' && expr[j] <= '9')
				{
					num = num * 10 + expr[j] - '0';
					j++, k++;
				}
				while(k--)
					num /= 10.0;
			}
			i = j;
			num *= flag;
//			printf("[DEBUG]%lf\n", num);
			st[ptr++] = num;
		}else{
//			printf("[DEBUG]");
//			for(debug = 0;debug < ptr;debug++)
//				printf("%lf ", st[debug]);
//			printf("\n");
//			printf("[DEBUG]ptr: %d\n", ptr);
			if(ptr < 2)
				return Infinity;
			num2 = st[--ptr];num1 = st[--ptr];
			switch(expr[i])
			{
				case '+': num = num1 + num2;break;
				case '-': num = num1 - num2;break;
				case '*': num = num1 * num2;break;
				case '/': if(eq(num2, 0)) return Infinity; num = num1 / num2;break;
				default: return Infinity;break;
			}
			st[ptr++] = num;
			// printf("[DEBUG]ptr: %d\n", ptr);
		}
	}
//	printf("[DEBUG]ptr: %d\n", ptr);
//	printf("[DEBUG]");
//	for(debug = 0;debug < ptr;debug++)
//		printf("%lf ", st[debug]);
//	printf("\n");
	if(ptr == 1)
		return st[0];
	else
		return Infinity;
}
