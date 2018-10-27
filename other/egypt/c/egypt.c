#include "BigNum.h"  
int main(void)
{
	int i,j,a,c;
	struct BigNum b,p,CONST_1;
	BigNumInitate(&CONST_1,1);
	for(i=1;i<=10000;i++)
		for(j=1;j<i;j++){
			BigNumInitate(&b,i);
			a=j;
			printf("%d/",a);
			BigNumPrint(b);
			putchar('=');
			while(c=BigNumDivide(b,a,&p)){
				a-=c;
				BigNumAdd(p,CONST_1,&p);
				BigNumMultiply(b,p,&b);
				if(j>=1) printf("1/");
				BigNumPrint(p);
				putchar('+');
			}
			printf("1/");
			BigNumPrint(p);
			putchar('\n');
		}
}
