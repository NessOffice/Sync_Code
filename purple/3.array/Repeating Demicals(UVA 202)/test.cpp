#include <stdio.h>
int main(){
	int a,b;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d %d",&a,&b)!=EOF){
	    int c[3000],d[3000],begin,end=0,flag=0,div=a;
	    while(!flag){
	        div=div-div/b*b;
	        div*=10;
	        d[end]=div;
	        c[end]=div/b;
	        for(begin=0;begin<end;begin++){
	            if(d[begin]==d[end]){
	                flag=1;
	                break;
	            }
	        }
	        end++;
	    }
	    printf("%d/%d = %d.",a,b,a/b);
	    for(int i=0;i<begin;i++)
	        printf("%d",c[i]);
	    putchar('(');
	    for(int i=begin;i<end-1 && i<50;i++)
	        printf("%d",c[i]);
	    if(end-1>50) printf("...");
	    printf(")\n");
	    printf("   %d = number of digits in repeating cycle\n\n",end-begin-1);
	}
	return 0;
}
