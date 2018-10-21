#include <stdio.h>
void PrintCross(int r,int c,int type,char** ps,int** pst){
	for(int i=0;i<r;i++){
		int t,j=0,flag=1;
		while(j<c){
			if(type)
				if(*(*(pst+i)+j) && (i==0||*(*(ps+i-1)+j)=='*')){
					printf("%3d.",*(*(pst+i)+j));
					for(t=i;t<r && (*(*(ps+t)+j))!='*';t++) printf("%c",*(*(ps+t)+j));
					printf("\n");
				}
			else{
				if(*(*(pst+i)+j) && flag){
					flag=0;
					printf("%3d.",*(*(pst+i)+j));
				}
				if(*(*(ps+i)+j)!='*') printf("%c",*(*(ps+i)+j));
				if(!flag&&(*(*(ps+i)+j)=='*'||j==c-1)){
					flag=1;
					printf("\n");
				}
			}
			j++;
		}
	}
}
int main(){
	int kase=0,r,c;
	char s[11][11];char** ps;char* ps1[11];ps=ps1;
	int status[11][11];int** pst;int* pst1[11];pst=pst1;
	for(int i=0;i<=11;i++){
		ps1[i]=s[i];
		pst1[i]=status[i];
	}
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
		PrintCross(r,c,0,ps,pst);
		printf("Down\n");
		PrintCross(r,c,1,ps,pst);
	}
	return 0;
}
