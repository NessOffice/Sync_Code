#include <cstdio>
#define maxn 100050 
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,a[maxn],c;
	scanf("%d",&n);
	for(int i=1;i<=100000;i++) a[i]=0;
	for(int i=1;i<100000;i++){
		int j,b;
		j=b=i;
		while(j){b+=j%10;j/=10;}
		if(!a[b]) a[b]=i;
	}
	while(n--){
		scanf("%d",&c);
		printf("%d\n",a[c]);
	}
	return 0;
} 
