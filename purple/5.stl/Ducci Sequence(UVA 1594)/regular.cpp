#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<vector<int> > IDCache;
int abs2(int a)
{
	return a>0?a:(-a);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		IDCache.clear();
		vector<int> ducci;
		int len,temp;
		cin>>len;
		for(int i = 0;i < len;i++)
		{
			cin>>temp;
			ducci.push_back(temp);
		}
		while(1)
		{
			int sum = 0;
			for(int i = len - 1;i>=0;i--)
			{
				sum += ducci[i];
			}
			if(sum == 0)
			{
				cout<<"ZERO\n";
				break;
			}
			if(IDCache.count(ducci))
			{
				cout<<"LOOP\n";
				break;
			}
			IDCache.insert(ducci);
			temp = ducci[len - 1];
			ducci[len - 1] = abs2(ducci[len - 1] - ducci[0]);
			for(int i = 0;i < len - 2;i++)
			{
				ducci[i] = abs2(ducci[i] - ducci[i+1]);
			}
			ducci[len-2] = abs2(ducci[len-2] - temp);
		}
	}
	return 0;
}
