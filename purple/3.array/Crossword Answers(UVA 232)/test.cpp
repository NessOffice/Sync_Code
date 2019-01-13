#include <stdio.h> 
int main(){
	int kase=0,r,c;
	char s[11][11];
	int status[11][11];
	while(scanf("%d",&r)&&r){
		scanf("%d",&c);
		int num=1;
		for(int i=0;i<r;i++){
			scanf("%s",s[i]);
			for(int j=0;j<c;j++){
				status[i][j]=0;
				if(s[i][j]!='*')
					if(!i||!j) status[i][j]=num++;
					else if(s[i-1][j]=='*'||s[i][j-1]=='*') status[i][j]=num++;
			}
		}
		if(kase++) printf("\n");
		printf("puzzle #%d:\n",kase);
		printf("Across\n");
		for(int i=0;i<r;i++){
			int j=0,flag=1;
			while(j<c){
				if(status[i][j] && flag){
					flag=0;
					printf("%3d.",status[i][j]);
				}
				if(s[i][j]!='*') printf("%c",s[i][j]);
				if(!flag&&(s[i][j]=='*'||j==c-1)){
					flag=1;
					printf("\n");
				}
				j++;
			}
		}
		printf("Down\n");
		for(int i=0;i<r;i++){
			int t,j=0,flag=1;
			while(j<c){
				if(status[i][j] && (i==0||s[i-1][j]=='*')){
					printf("%3d.",status[i][j]);
					for(t=i;t<r && s[t][j]!='*';t++) printf("%c",s[t][j]);
					printf("\n");
				}
				j++;
			}
		}
	}
	return 0;
}
