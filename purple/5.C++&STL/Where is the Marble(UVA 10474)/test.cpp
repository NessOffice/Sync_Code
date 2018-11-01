#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	const int maxn=10010;
	int a[maxn];
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q,x,pos,kase=1;
	while(cin>>n>>q && n)
	{
		cout<<"CASE# "<<kase++<<":\n";
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		while(q--)
		{
			cin>>x;
			pos=lower_bound(a,a+n,x)-a;
			if(a[pos]==x) cout<<x<<" found at "<<pos+1<<endl;
			else cout<<x<<" not found\n";
		}
	}
	return 0;
}
