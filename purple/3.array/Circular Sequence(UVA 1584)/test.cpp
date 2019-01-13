#include <stdio.h>
#include <string.h>
#define maxn 105
int less(char* s,int p,int q,int len){
	for(int i=0;i<len;i++)
		if(s[(i+p)%len]!=s[(i+q)%len])
			return s[(i+p)%len]<s[(i+q)%len];
	return 0;
} 
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	char s[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int ans=0,len=strlen(s);
		for(int i=1;i<len;i++){
			if(less(s,i,ans,len)) ans=i;
		}
		for(int i=0;i<len;i++) putchar(s[(i+ans)%len]);
		putchar('\n');
	}
	return 0;
} 
