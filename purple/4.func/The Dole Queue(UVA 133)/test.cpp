#include <cstdio>
int main(){
	int N,m,k,circle[21];
	while(scanf("%d %d %d",&N,&m,&k) && N){
		for(int g=1;g<=N;g++) circle[g]=1;
		int num=N,i=0,j=N+1;
		while(num){
			for(int g=0;g<m;g++){
				i++;if(i==N+1) i-=N;
				while(!circle[i]){i++;if(i==N+1) i-=N;}
			}
			for(int g=0;g<k;g++){
				j--;if(j==0) j+=N;
				while(!circle[j]){j--;if(j==0) j+=N;} 
			}
			circle[i]=circle[j]=0;
			if(i==j){num--;printf("%3d",i);}
			else{num-=2;printf("%3d%3d",i,j);}
			if(num) putchar(',');
		}
		putchar('\n');
	}
	return 0;
} /*
#include <cstdio>
int n,k,m,a[25];
int go(int p,int d,int t){
	while(t--)
		do{p=(p+d+n-1)%n+1;}while(a[p]==0);
	return p;
}
int main(){
    while(scanf("%d%d%d",&n,&k,&m)==3 && n){
    	for(int i=1;i<=n;i++) a[i]=i;
    	int left=n;
    	int p1=n,p2=1;
    	while(left){
	    	p1=go(p1,1,k);
	    	p2=go(p2,-1,m);
	    	printf("%3d",p1);left--;
	    	if(p2!=p1){printf("%3d",p2);left--;}
	    	a[p1]=a[p2]=0;
	    	if(left) printf(",");
	    }
	    printf("\n");
    }
    return 0;
}
