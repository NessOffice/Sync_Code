#include<bits/stdc++.h>
using namespace std;

#define	N 100099
char s[N];
int ss,l,a[N];

int main() 
{
	freopen("odious_in.txt","r",stdin);
	freopen("odious_out2.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;++i){
	
	memset(a,0,sizeof(a)); ss=0;
	scanf("%s",s+1);
	l=strlen(s+1); //1000000
	for(int i=1;i<=l;++i){
		if(s[i]<=57)a[l-i+1]=s[i]-48; else a[l-i+1]=s[i]-87;
	}
	
	for(int i=1;i<=l;++i){
		if(a[i]%2)ss^=1;
		if(a[i]/2%2)ss^=1;
		if(a[i]/4%2)ss^=1;
		if(a[i]/8%2)ss^=1;
	}
	
	for(int i=1;i<=l;++i)a[i]<<=1;
	if(!ss)++a[1];
	for(int i=1;i<=l;++i){
		if(a[i]>=16){
			a[i]-=16;
			++a[i+1];
		}
	}
	if(a[l+1])++l;
	for(int i=l; i; --i){
		if(a[i]<10)printf("%c",a[i]+48);
			 else printf("%c",87+a[i]);
	}
	
	puts("");
	
	}
}
