#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;
const int maxn=27;
vector<int> pile[maxn];
int n;
void find_block(int a, int& p, int& h)
{
	for(p=0;p<n;p++)
		for(h=0;h<pile[p].size();h++)
			if(pile[p][h]==a) return;
}
void clear_above(int p, int h)
{
	for(int i=h+1;i<pile[p].size();i++)
	{
		int b=pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h+1);
}
void pile_onto(int p1, int p2, int h)
{
	for(int i=h;i<pile[p1].size();i++)
	{
		int b=pile[p1][i];
		pile[p2].push_back(b);
	}
	pile[p1].resize(h);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s1,s2;
	int a,b,pa,pb,ha,hb;cin>>n;
	for(int i=0;i<n;i++) pile[i].push_back(i);
	while(cin>>s1)
	{
		if(s1=="quit") break;
		cin>>a>>s2>>b;
		find_block(a,pa,ha);
		find_block(b,pb,hb);
		if(pa==pb) continue;
		if(s1=="move") clear_above(pa,ha);
		if(s2=="onto") clear_above(pb,hb);
		pile_onto(pa,pb,ha);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<':';
		for(int j=0;j<pile[i].size();j++)
			cout<<' '<<pile[i][j];
		cout<<endl;
	}
	return 0;
}
