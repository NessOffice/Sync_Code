#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define EPS 1e-6
using namespace std;
double x, y;
struct MAP
{
	string name;
	double x1,y1,x2,y2;
	double w,h,r,a,l;
	pair<double, double> c;
	
	MAP(double _x1, double _y1, double _x2, double _y2, string _name):
		x1(_x1), y1(_y1), x2(_x2), y2(_y2), name(_name){
			if(x1 > x2) swap(x1, x2);
			if(y1 > y2) swap(y1, y2);
			w = x2 - x1, h = y2 - y1;
			r = h / w, a = w * h;
			c.first = (x1 + x2) / 2, c.second = (y1 + y2) / 2;
		}
	bool operator < (const MAP &b) const
	{
		if(l != b.l) return l > b.l;
		double d1 = (c.first-x)*(c.first-x) + (c.second-y)*(c.second-y);
		double d2 = (b.c.first -x)*(b.c.first-x) + (b.c.second-y)*(b.c.second-y);
		if(fabs(d1 - d2) > EPS) return d1 < d2;
		d1 = (r - 0.75), d2 = (b.r - 0.75);
		if(fabs(d1 - d2) > EPS) return d1 < d2;
		d1 = (x2-x)*(x2-x) + (y2-y)*(y2-y);
		d2 = (b.x2-x)*(b.x2-x) + (b.y2-y)*(b.y2-y);
		if(fabs(d1 - d2) > EPS) return d1 < d2;
		return x1 < b.x1;
	}
};
vector<MAP> maps;
map<string, pair<double, double> > locations;
bool cover(int i)
{
	if(maps[i].x1 <= x && x <= maps[i].x2)
	if(maps[i].y1 <= y && y <= maps[i].y2)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string name;cin>>name;
	while(cin>>name && name != "LOCATIONS")
	{
		double x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		maps.push_back(MAP(x1,y1,x2,y2,name));
	}
	while(cin>>name && name != "REQUESTS")
	{
		cin>>x>>y;
		locations[name] = make_pair(x, y);
	}
	while(cin>>name && name != "END")
	{
		int level;cin>>level;
		cout<<name<<" at detail level "<<level;
		if(!locations.count(name)) cout<<" unknown location\n";
		else
		{
			x = locations[name].first, y = locations[name].second;
			vector<MAP> OK;
			vector<double> area;
			for(int i = maps.size();i >= 0;i--)
			{
				if(cover(i))
				{
					OK.push_back(maps[i]);
					area.push_back(maps[i].a);
				}
			}
			if(OK.size() == 0) cout<<" no map contains that location\n"; 
			else
			{
				sort(area.begin(), area.end(), greater<double>());
				unique(area.begin(), area.end());
				int len1 = OK.size(), len2 = area.size();
				for(int i = 0;i < len1;i++)
					for(int j = 0;j < len2;j++)
						if(OK[i].a == area[j]) {OK[i].l = j + 1;break;}
				sort(OK.begin(), OK.end());
				if(len2 < level) cout<<" no map at that detail level;";
				int temp = 0;
				for(int i = 0;i < len1;i++)
					if(OK[i].l == level){temp = i;break;}
				cout<<" using "<<OK[temp].name<<endl;
			}
		}
	}
	return 0;
}
