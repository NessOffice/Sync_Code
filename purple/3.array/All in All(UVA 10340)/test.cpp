#include <stdio.h>
#include <string.h>
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char str1[100005],str2[100005];
	while(scanf("%s %s",str1,str2)!=EOF){
		int len1=strlen(str1),len2=strlen(str2),index=0;
		for(int i=0;i<len2 && index<len1;i++)
			if(str2[i]==str1[index])
				index++;
		if(index==len1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
