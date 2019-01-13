#include <stdio.h>
#define MAXN 1000
int main(){
	int n,A[12],B[12],C[12],sleeper,t,kase=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&n) && n){
		t=1;sleeper=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&A[i],&B[i],&C[i]);
			if(C[i]>A[i]) sleeper++;
		}
		while(sleeper && t<MAXN){
			for(int i=0;i<n;i++){
				if(C[i]==A[i]){
					if(sleeper>n/2) sleeper++;
					else C[i]=0;
				}
			}
			for(int i=0;i<n;i++){
				if(C[i]==A[i]+B[i]){
					sleeper--;
					C[i]=0;
				}
			}
			for(int i=0;i<n;i++) C[i]++;
			t++;
		}
		if(t>=MAXN) t=-1;
		printf("Case %d: %d\n",kase++,t);
	}
	return 0;
}
