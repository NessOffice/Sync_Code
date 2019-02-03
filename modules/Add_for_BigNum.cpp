#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	char a[505],b[505],c[505];
	int i;
	scanf("%s%s",a,b);
	int lena=strlen(a),lenb=strlen(b);
	for(i=0;i<lena/2;i++)
		swap(a[i],a[lena-1-i]);
	for(i=0;i<lenb/2;i++)
		swap(b[i],b[lenb-1-i]);
	for(i=lena;i<=500;i++) a[i]='0';
	for(i=lenb;i<=500;i++) b[i]='0';
	int len=lena>lenb?lena:lenb;
	int carry=0;
	for(i=0;i<len;i++){
		c[i]=a[i]+b[i]-'0';
		if(carry){
			c[i]++;
			carry=0;
		}
		if(c[i]>'9'){
			c[i]=c[i]-'9'-1+'0';
			carry=1;
		}
	}
	if(carry) cout<<1;
	for(i=len-1;i>=0;i--) printf("%c",c[i]); 
	printf("\n"); 
	return 0;
} 
