#include <stdio.h>
#include <string.h>
int main(){
	int a[10][10],n,tot,x,y;
	while(scanf("%d",&n)==1){
		memset(a,0,sizeof(a));
		tot = a[x=0][y=n-1] = 1;
		while(tot<n*n){
			while(x<n-1 && !a[x+1][y]) a[++x][y] = ++tot;
			while(y>0 && !a[x][y-1]) a[x][--y] = ++tot;
			while(x>0 && !a[x-1][y]) a[--x][y] = ++tot;
			while(y<n-1 && !a[x][y+1]) a[x][++y] = ++tot;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%2d ",a[i][j]);
				printf("\n");
		}
	}
	return 0;
} 
