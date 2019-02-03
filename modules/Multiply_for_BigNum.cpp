#include <stdio.h>
#include <string.h>
struct BigNum{
	char num[100];
	int len;
}; 
void swap(char *a,char *b){char t=*a;*a=*b;*b=t;}
void add(char *a,char *b,int *lenp,int lena,int zero,char *c){
	int len=*lenp>lena?:*lenp:lena;
	for(i=*lenp;i<len;i++) a[i]='0';
	for(i=lena;i<len;i++) b[i]='0';
	int carry=0,i;
	for(i=0;i<len;i++){
		j=i+zero;
		c[j]=a[i]+b[i]-'0';
		if(carry){c[j]++;carry=0;}
		if(c[j]>'9'){c[j]-=10;carry=1;}
	}
	if(carry){c[(*lenp)++]=1;c[*lenp]='\0';}
}
void multiply(char *a,char *b,int *lenp,int lenb,int lena,char *c){
	for(int i=0;i<lenb;i++){
		for(int j=0;j<b[i]-'0';j++)
			add(c,a,lenp,lena,i,c);
	}
	for(int i=(*lenp-1);i>=0;i--) printf("%c",c[i]); 
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
	int len=1;
	int *lenp=&len;
	for(i=lena;i<len;i++) a[i]='0';
	for(i=lenb;i<len;i++) b[i]='0';
	a[len]=b[len]='\0';
	c[0]='0';c[1]='\0';
	if(lena>lenb) multiply(a,b,lenp,lenb,lena,c);
	else multiply(b,a,lenp,lena,lenb,c);
	printf("\n");
	return 0;
} 
