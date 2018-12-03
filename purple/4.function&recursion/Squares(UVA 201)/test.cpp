#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n,m,kase=0,i,j,H[10][10],V[10][10];
	char c;
	freopen("in.txt","r",stdin);
	std::ios::sync_with_stdio(false);
	while(cin>>n>>m){
		for(i=0;i<10;i++) for(j=0;j<10;j++) H[i][j]=V[i][j]=0;
		while(m--){
			cin>>c>>i>>j;
			if(c=='H') H[i][j]=1;else V[j][i]=1;
		}
		int sum=0; 
		if(kase++) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kase);
		for(int k=1;k<n;k++){
			int count=0;
			for(i=1;i<=n-k;i++)
			for(j=1;j<=n-k;j++){
				int flag=1;
				for(int i0=i;i0<i+k;i0++)
					if(V[i0][j]!=1 || V[i0][j+k]!=1) flag=0;
				for(int j0=j;j0<j+k;j0++)
					if(H[i][j0]!=1 || H[i+k][j0]!=1) flag=0;
				count+=flag;
			}
			if(count) printf("%d square (s) of size %d\n",count,k);
			sum+=count;
		}
		if(!sum) printf("No completed squares can be found.\n");
	}
	return 0;
}
