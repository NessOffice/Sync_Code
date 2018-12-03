#include <iostream>
#include <vector>
using namespace std;
int abs2(int a)
{
	return a>0?a:(-a);
}
int main(){
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		vector<int> ducci;
		int len,temp,sum;
		cin>>len;
		for(int i = 0;i < len;i++)
		{
			cin>>temp;
			ducci.push_back(temp);
		}
		for(int j = 0;j < 210;j++)
		{
			sum = 0;
			for(int i = len - 1;i >= 0;i--)
			{
				sum += ducci[i];
			}
			if(sum == 0)
			{
				cout<<"ZERO\n";
				break;
			}
			temp = ducci[len - 1];
			ducci[len - 1] = abs2(ducci[len - 1] - ducci[0]);
			for(int i = 0;i < len - 2;i++)
			{
				ducci[i] = abs2(ducci[i] - ducci[i+1]);
			}
			ducci[len-2] = abs2(ducci[len-2] - temp);
		}
		if(sum) cout<<"LOOP\n";
	}
	return 0;
}
