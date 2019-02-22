#include <iostream>
using namespace std;
int main(){
	int n,m,i=0;
	cin>>n>>m;
	char b[102];
	while(n){
		b[i++]=n%m+'0';
		n/=m;
	}
	while(i--){
		if(b[i]>'9') b[i]=b[i]-'9'+'A'-1;
		cout<<b[i];
	}
	return 0;
}
