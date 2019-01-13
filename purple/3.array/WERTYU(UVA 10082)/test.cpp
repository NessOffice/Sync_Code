#include <cstdio>
char jp[] ="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
    int a,i;
    while((a=getchar())!=EOF){
    	for(i=1;jp[i]&&a!=jp[i];i++);
    	if(jp[i]) putchar(jp[i-1]);
    	else putchar(a);
	}
    return 0;
}
