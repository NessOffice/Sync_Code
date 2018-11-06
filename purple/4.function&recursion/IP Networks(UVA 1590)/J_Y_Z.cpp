#include <cstdio> 
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
int x[1001][9],y[1001][9],z[1001][9],u[1001][9],sum[1001][33];
int turn(int a,int x[][9],int i){
	int k=128,t=1;
	while(t<=8){
		if(a>=k){
			a-=k;
			x[i][t]=1;
		}
		else  x[i][t]=0;
		k/=2;
		t++;
	}
}
int exturn(int x[][9]){
	int sum=0;
	rep(i,1,8)
		if(x[1][i]==1)  sum+=(1<<(8-i));
	return sum;
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("in_wrong.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,a,b,c,d;
	while(scanf("%d",&n)==1){
		if(n==1){
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			printf("%d.%d.%d.%d\n",a,b,c,d);
			printf("255.255.255.255\n");
		}
		else{
			rep(i,1,n){
				scanf("%d.%d.%d.%d",&a,&b,&c,&d);
				turn(a,x,i);
				turn(b,y,i);
				turn(c,z,i);
				turn(d,u,i);
			}
			rep(i,1,n) rep(j,1,8) {
				sum[i][j]=x[i][j];
				sum[i][j+8]=y[i][j];
				sum[i][j+16]=z[i][j];
				sum[i][j+24]=u[i][j];
			}
			/*rep(i,1,n) {
				rep(j,1,32) cout<<sum[i][j]<<" ";
				cout<<endl;
			}*/
			int k=0;
			rep(j,1,32){
				bool flag=true;
				rep(i,2,n){
					if(sum[i][j]!=sum[1][j]) {
						flag=false;
						k=j;
						break;
					}
				}
				if(!flag) break;
			}
			//cout<<k<<endl;
			if(k==0){
	    		printf("%d.%d.%d.%d\n",a,b,c,d);
	    		printf("255.255.255.255\n");
			}
			else if(k<=8&&k>0){
				int yan=0;
				rep(j,k,8) rep(i,1,n) x[i][j]=0;
	    		printf("%d.0.0.0\n",exturn(x));
	    		rep(t,9-k,7)	yan+=(1<<t);
				printf("%d.0.0.0\n",yan);
			}
			else if(k<=16&&k>8){
				int yan=0;
				rep(j,k-8,8) rep(i,1,n) y[i][j]=0;
				printf("%d.%d.0.0\n",a,exturn(y));
				rep(t,17-k,7)   yan+=(1<<t);
				printf("255.%d.0.0\n",yan);
			}
			else if(k<=24&&k>16){
				int yan=0;
				rep(j,k-16,8) rep(i,1,n) z[i][j]=0;
				printf("%d.%d.%d.0\n",a,b,exturn(z));
				rep(t,25-k,7)   yan+=(1<<t);
				printf("255.255.%d.0\n",yan);
			}
			else{
				int yan=0;
				rep(j,k-24,8) rep(i,1,n) u[i][j]=0;
				printf("%d.%d.%d.%d\n",a,b,c,exturn(u));
				rep(t,33-k,7)   yan+=(1<<t);
				printf("255.255.255.%d\n",yan);
			}
		}
	}
	return 0;
}
