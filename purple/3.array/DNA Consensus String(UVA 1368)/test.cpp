#include <stdio.h>
#include <string.h>
#define maxn 1005 
int main(){
	int t,m,n,fre[maxn][5],index,most,sum;
	char strin[maxn];
	scanf("%d",&t);
	while(t--){
		sum=0;
		memset(fre,0,sizeof(fre));
		scanf("%d %d",&m,&n);
		for(int i=0;i<m;i++){
			scanf("%s",strin);
			for(int j=0;j<n;j++)
				switch(strin[j]){
					case 'A':fre[j][0]++;break;
					case 'C':fre[j][1]++;break;
					case 'G':fre[j][2]++;break;
					case 'T':fre[j][3]++;break;
				}
		}
		for(int i=0;i<n;i++){
			most=fre[i][0];index=0;
			for(int j=1;j<4;j++)
				if(fre[i][j]>most){
					most=fre[i][j];
					index=j;
				}
			switch(index){
				case 0:putchar('A');break;
				case 1:putchar('C');break;
				case 2:putchar('G');break;
				case 3:putchar('T');break;
			}
			sum=sum+m-fre[i][index];
		}
		printf("\n%d\n",sum);
	}
	return 0;
} 
