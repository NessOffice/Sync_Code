#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=1000 + 10;
int main(){
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,temp,kase=1;
	char op[9];
	while(cin>>n && n)
	{
		queue<int> q[maxn],q2;
		cout<<"Scenario #"<<kase++<<endl;
		map<int,int> team;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>temp;
				team[temp]=i;
			}
		}
		while(cin>>op && op[0]!='S')
		{
			if(op[0]=='E')
			{
				cin>>temp;
				int x=team[temp];
				if(q[x].empty()) q2.push(x);
				q[x].push(temp);
			}
			else
			{
				int x=q2.front();
				while(q[x].empty()) {q2.pop();x=q2.front();}
				cout<<q[x].front()<<endl;
				q[x].pop();
				if(q[x].empty()) q2.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}
