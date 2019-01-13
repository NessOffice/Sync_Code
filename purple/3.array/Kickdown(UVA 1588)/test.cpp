#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 100
using namespace std;
int len1,len2,SumLen;
int MinLen(char *s1,char *s2,int l){
	int len=SumLen;
	for(int i=0;i<l;i++){
		int minl=min(len1,len2),fix=min(minl,l-i),ok=1;
		for(int j=0;j<fix;j++)
			if(s1[i+j]=='2' && s2[j]=='2') {ok=0;break;}
		if(ok){len=SumLen-fix;break;}
	}
	return len;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s1[MAXN+2],s2[MAXN+2];
	while(scanf("%s %s",s1,s2)!=EOF){
		len1=strlen(s1),len2=strlen(s2),SumLen=len1+len2;
		printf("%d\n",min(MinLen(s1,s2,len1),MinLen(s2,s1,len2)));
	} 
	return 0;
} 
