#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<vector<int>, int> IDCache;
int abs2(int a)
{
	return a>0?a:(-a);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		IDCache.clear();
		vector<int> ducci;
		int flag = 1,len,temp;
		cin>>len;
		for(int i = 0;i < len;i++)
		{
			cin>>temp;
			ducci.push_back(temp);
		}
		for(int j = 0;j < 1000;j++)
		{
			int sum = 0;
			for(int i = ducci.size() - 1;i>=0;i--)
			{
				sum += ducci[i];
			}
			if(sum == 0)
			{
				cout<<"ZERO\n";
				flag = 0;
				break;
			}
			if(IDCache.count(ducci))
			{
				cout<<"LOOP\n";
				flag = 0;
				break;
			}
			IDCache[ducci] = 1;
			temp = ducci[len - 1];
			ducci[len - 1] = abs2(ducci[len - 1] - ducci[0]);
			for(int i = 0;i < len - 2;i++)
			{
				ducci[i] = abs2(ducci[i] - ducci[i+1]);
			}
			ducci[len-2] = abs2(ducci[len-2] - temp);
		}
		if(flag) cout<<"LOOP\n";
	}
	return 0;
}
