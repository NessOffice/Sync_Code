#include <cstdio>
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c,q=1;
	while((c=getchar())!=EOF){
		if(c=='"'){
			printf("%c",q?"``":"''");
			q=!q;
		}
		else printf("%c",c); 
	}
	return 0;
} 
