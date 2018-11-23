#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,A,B;
	while(cin>>n && n)
	{
		map<int, int> from;
		map<int, int> to;
		set<int> ACache;
		set<int> BCache;
		while(n--)
		{
			cin>>A>>B;
			if(from[A] == 0) ACache.insert(A);
			from[A]++;
			if(to[B] == 0) BCache.insert(B);
			to[B]++;
			if(ACache.count(B))
			{
				from[B]--;
				to[B]--;
			}
			if(BCache.count(A))
			{
				from[A]--;
				to[A]--;
			}
			if(from[A] == 0) ACache.erase(A);
			if(to[A] == 0) BCache.erase(A);
			if(from[B] == 0) ACache.erase(B);
			if(to[B] == 0) BCache.erase(B);
		}
		if(ACache.size() == 0
		&& BCache.size() == 0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
