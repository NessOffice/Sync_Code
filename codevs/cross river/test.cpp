#include <iostream>
using namespace std;
long long a[25][25],d[25][25];
int main(){
	int n,m,x,y;cin>>n>>m>>x>>y;
	d[x][y]=d[x+2][y-1]=d[x+2][y+1]=1;
	d[x-2][y-1]=d[x-2][y+1]=d[x-1][y+2]=1;
	d[x-1][y-2]=d[x+1][y+2]=d[x+1][y-2]=1;
	for(int i=1;i<=n;i++){if(!d[i][0]) a[i][0]=1;else break;}
	for(int i=1;i<=m;i++){if(!d[0][i]) a[0][i]=1;else break;}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!d[i][j]) a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][m];
	return 0;
}
