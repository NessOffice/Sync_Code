#include <cstdio>
#define maxn 1010
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase=0,n,a[maxn],b[maxn],c[10],d[10];
	while(scanf("%d",&n)==1&&n){
		printf("Game %d:\n",++kase);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(;;){
			int A=0,B=0;
			for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				if(a[i]==b[i]) A++;
			}
			if(!b[0]) break;
			for(int i=1;i<10;i++) c[i]=d[i]=0;
			for(int i=0;i<n;i++){
				c[a[i]]++;
				d[b[i]]++;
			}
			for(int i=1;i<10;i++) B+=c[i]<d[i]?c[i]:d[i];
			B-=A;
			printf("    (%d,%d)\n",A,B);
		}
	}
	return 0;
} 
