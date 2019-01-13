#include <stdio.h>
#include <string.h>
int main(){
	int n,len; 
	scanf("%d",&n);
	while(n--){
		char s[90];
		scanf("%s",s);
		len=strlen(s);
		for(int T=1;T<len;T++){
			if(len%T==0){
				int flag=1;
				for(int j=T;j<len;j++){
					if(s[j]!=s[j%T]){flag=0;break;}
				}
				if(flag){
					printf("%d\n",T);
					if(n) printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}
