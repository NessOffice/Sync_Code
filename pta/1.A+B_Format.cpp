#include <stdio.h>
int main(){
	int a,b,c,d[10],n=0,i;
	scanf("%d%d",&a,&b);
	c=(a+b>0)?(a+b):(-a-b);
	if(a+b<0) putchar('-');
	while(c/1000){
		d[++n]=c%1000;
		c/=1000;
	}
	printf("%d",c);
	for(i=n;i>0;i--)
		printf(",%03d",d[i]);
	return 0;
} 
