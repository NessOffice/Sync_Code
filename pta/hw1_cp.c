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
		if((expr[i] >= '0' && expr[i] <= '9') || (expr[i] == '-' && expr[i] != len-1 && (expr[i+1] >= '0' && expr[i+1] <= '9')))
		{
			st[ptr++] = atof(expr + i);
			while(expr[i] == '-' || expr[i] == '.' || (expr[i] >= '0' && expr[i] <= '9')) i++;
		}else{
			// printf("[DEBUG]");
			// for(debug = 0;debug < ptr;debug++)
			// 	printf("%lf ", st[debug]);
			// printf("\n");
			// printf("[DEBUG]ptr: %d\n", ptr);
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
		}
	}
	if(ptr == 1)
		return st[0];
	else
		return Infinity;
}
