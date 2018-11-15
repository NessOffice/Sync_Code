#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,tempA,tempB;
	while(cin>>n && n)
	{
		//map<int, int>
		set<int> ACache;
		set<int> BCache;
		int A = 0, B = 0;
		while(n--)
		{
			cin>>tempA>>tempB;
			if(ACache.count(tempB))
			{
				A--;
				ACache.erase(tempB); 
			} 
			else
			{
				BCache.insert(tempB);
				B++;
			}
			if(BCache.count(tempA))
			{
				B--;
				BCache.erase(tempA);
			} 
			else
			{
				ACache.insert(tempA);
				A++;
			}
		}
		if(ACache.size() == 0 && BCache.size() == 0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
