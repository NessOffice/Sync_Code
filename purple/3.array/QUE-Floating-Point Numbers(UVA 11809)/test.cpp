#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s[30];
	double p,M[10][32],m,x;
	long long q,E[10][32],e;
	for(int i=0;i<=9;i++)
		for(int j=1;j<=30;j++){
			e=pow(2,j)-1;
			m=1-1/(pow(2,i+1));
			x=log10(m)+e*log10(2);
			E[i][j]=floor(x);
			M[i][j]=pow(10,x-E[i][j]);
		}
	while(cin>>s && s!="0e0"){
		s[17]=' ';
		sscanf(s,"%lf %d",&p,&q);
		for(int i=0;i<=9;i++)
			for(int j=1;j<=30;j++)
				if(fabs(p-M[i][j])<1e-4 && q==E[i][j])
					cout<<i<<' '<<j<<endl;
	}
	return 0;
}
