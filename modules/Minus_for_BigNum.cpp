#include <stdio.h>
#include <string.h>
void swap(char *a,char *b){char t=*a;*a=*b;*b=t;}
void subtract(char *a,char *b,int flag,int len,char *c){
	int carry=0,zero=0;
	for(int i=0;i<len;i++){
		c[i]=a[i]-b[i]+'0';
		if(carry){c[i]--;carry=0;}
		if(c[i]<'0'){c[i]+=10;carry=1;}
	}
	for(int i=len-1;i>=0;i--){zero++;if(c[i]!='0') break;}
	if(flag<0) putchar('-');
	for(int i=len-zero;i>=0;i--) printf("%c",c[i]); 
}
int main(){
	char a[505],b[505],c[505];
	int i,flag=0;
	scanf("%s %s",a,b);
	int lena=strlen(a),lenb=strlen(b);
	for(i=0;i<lena/2;i++)
		swap(a+i,a+lena-1-i);
	for(i=0;i<lenb/2;i++)
		swap(b+i,b+lenb-1-i);
	int len=lena>lenb?lena:lenb;
	for(i=lena;i<len;i++) a[i]='0';
	for(i=lenb;i<len;i++) b[i]='0';
	a[len]=b[len]='\0';
	for(i=len-1;i>=0;i--){
		if(a[i]>b[i]){flag=1;break;}
		if(b[i]>a[i]){flag=-1;break;}
	}
	if(flag>=0) subtract(a,b,flag,len,c);
	else subtract(b,a,flag,len,c);
	printf("\n"); 
	return 0;
} 
