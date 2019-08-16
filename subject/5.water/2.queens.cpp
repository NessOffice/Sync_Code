#include <iostream>
#include <cstring>
using namespace std;
int n, fn = 0, x[16], vis[3][40];
void back(int k)
{
	if(k == n)
	{
		fn++;
		if(fn <= 3)
		{
			for(int i = 0;i < n-1;i++)
				cout<<x[i]+1<<' ';
			cout<<x[n-1]+1<<endl;
		}
		return;
	}
	for(int i = 0;i < n;i++)
	{
		if(!vis[0][i] && !vis[1][i+k] && !vis[2][i-k+n])
		{
			vis[0][i] = vis[1][i+k] = vis[2][i-k+n] = 1;
			x[k] = i;
			back(k+1);
			vis[0][i] = vis[1][i+k] = vis[2][i-k+n] = 0;
		}
	}
}
int main()
{
	memset(vis, 0, sizeof(vis));
	cin>>n;
	back(0);
	cout<<fn;
	return 0;
}