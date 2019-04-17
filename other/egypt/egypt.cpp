#include "BigNum.h"  
int main(void)
{
	for(int i=1;i<=10000;i++)
		for(int j=1;j<i;j++){
			BigNum b=i;
			int a=j;
			printf("%d/",a);b.print();
			while(b%a){
				BigNum p=b/a;
				int c=b%a;
				a=a-c;
				b=b*(p+1);
				if(j>1) putchar('+');putchar('1');putchar('/');(p+1).print();
			}
			putchar('+');putchar('1');putchar('/');(b/a).print();putchar('\n');
		}
}
