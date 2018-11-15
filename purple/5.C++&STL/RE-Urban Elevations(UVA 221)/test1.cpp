#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Building
{
	int ID;
	int x;
	int y;
	int width;
	int depth;
	int height;
	int x1;
	int x2;
}; 
vector<Building> building;
vector<int> seen;
vector<int> X;
map<int, int> counts;
int n;
int cmp(Building a, Building b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool Updata(int i, int x)
{
	for(int j = seen.size() - 1;j >= 0;j--)
	{
		if(building[j].x1 <= x)
		if(building[j].x2 >= x)
			if(building[j].height >= building[i].height)
			if(building[j].y < building[i].y)
				return true;
	}
	return false;
}
bool Visible(int x)
{
	for(int i = 0;i < n;i++)
	{
		if(building[i].x1 <= x)
		if(building[i].x2 >= x)
			if(Updata(i, x) == false)
			{
				seen.push_back(i);
			}
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase=1;
	while(cin>>n && n)
	{
		seen.clear();
		building.clear();
		X.clear();
		cout<<"For map #"<<kase++<<", the visible buildings are numbered as follows:\n";
		for(int i=0;i<n;i++)
		{
			Building temp;
			cin>>temp.x>>temp.y;
			cin>>temp.width>>temp.depth>>temp.height;
			temp.ID = i + 1;
			temp.x1 = temp.x;
			temp.x2 = temp.x1 + temp.width;
			building.push_back(temp);
		}
		sort(building.begin(),building.end(),cmp);
		/*
		for(int i = 0;i < n;i++)
		{
			cout<<building[i].x<<' ';
			cout<<building[i].y<<endl;
		}
		*/
		for(int i = 0;i < n;i++)
		{
			X.push_back(building[i].x1);
			X.push_back(building[i].x2);
		}
		sort(X.begin(), X.end());
		vector<int>::iterator it = unique(X.begin(), X.end());
		X.erase(it, X.end());
		int len = X.size();
		for(int i = 0;i + 1 < len;i++)
		{
			Visible((X[i] + X[i + 1])/2);
		}
		counts.clear();
		len = seen.size();
		for(int i = 0;i < len;i++)
		{
			int id = building[seen[i]].ID;
			if(counts.count(id) == 0)
			{
				if(i) cout<<' ';
				counts[id] = 1;
				cout<<id;
			}
		}
		cout<<endl;
	}
	return 0;
}
