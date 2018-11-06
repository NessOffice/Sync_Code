#include <iostream>
#include <set> 
#include <map>
#include <vector>
#include <string>
#include <stack> 
#include <algorithm>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int> Set;
stack<int> s;
vector<Set> SetCache;
map<Set,int> IDCache;
int ID(Set x)
{
	if(IDCache.count(x)) return IDCache[x];
	else SetCache.push_back(x);
	return IDCache[x] = SetCache.size() - 1; 
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string buf;
	int n,kase;cin>>kase;
	while(kase--)
	{
		cin>>n;
		while(n--)
		{
			cin>>buf;
			char op=buf[0];
			if(op=='P') s.push(ID(Set()));
			else if(op=='D') s.push(s.top());
			else
			{
				Set x1=SetCache[s.top()];s.pop();
				Set x2=SetCache[s.top()];s.pop();
				Set x;
				if(op=='U') set_union(ALL(x1),ALL(x2),INS(x));
				if(op=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
				if(op=='A') {x=x2;x.insert(ID(x1));}
				s.push(ID(x));
			}
			cout<<SetCache[s.top()].size()<<endl;
		}
		cout<<"***\n";
	}
	return 0;
}
