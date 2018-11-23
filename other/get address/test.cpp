#include <stdio.h>
int main(){
	int a,*b,*c;
	a=1;
	b=c=&a;
	printf("%x",b);
	return 0;
} 
