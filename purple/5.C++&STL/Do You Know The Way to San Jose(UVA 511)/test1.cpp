#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define EPS 1e-6
using namespace std;
double x, y, flag = 0;
struct MAP
{
	string name;
	double x1,y1,x2,y2;
	double w,h,r,a;
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
		if(flag)
		{
			if(a != b.a) return a > b.a;
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
		else return a > b.a;
	}
};
vector<int> level;
vector<MAP> maps;
map<string, pair<double, double> > locations;
void GetLevel()
{
	int len = maps.size();
	level.push_back(-1);
	level.push_back(0);
	for(int i = 1;i < len;i++)
	{
		if(maps[i].a != maps[i - 1].a)
			level.push_back(i);
	}
	level.push_back(len);
}
bool cover(int i)
{
	if(maps[i].x1 <= x && x <= maps[i].x2)
	if(maps[i].y1 <= y && y <= maps[i].y2)
		return true;
	return false;
}
void test()
{
	for(int i = 0;i < maps.size();i++)
		cout<<maps[i].name<<' '<<maps[i].a<<endl;
	for(int i = 0;i < level.size();i++)
		cout<<level[i]<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string name;
	cin>>name;
	while(cin>>name && name != "LOCATIONS")
	{
		double x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		maps.push_back(MAP(x1,y1,x2,y2,name));
	}
	sort(maps.begin(),maps.end());
	GetLevel();
	test();
	while(cin>>name && name != "REQUESTS")
	{
		cin>>x>>y;
		locations[name] = make_pair(x, y);
	}
	flag = 1;
	while(cin>>name && name != "END")
	{
		double rLevel;
		cin>>rLevel;
		cout<<name<<" at detail level "<<rLevel;
		if(locations.count(name) == 0) cout<<" unknown location\n";
		else
		{
			x = locations[name].first, y = locations[name].second;
			vector<MAP> OK;
			for(int i = level[rLevel];i < level[rLevel + 1];i++)
			{
				if(cover(i))
					OK.push_back(maps[i]);
			}
			if(OK.size() == 0) cout<<" no map contains that location\n"; 
			else
			{
				sort(OK.begin(), OK.end());
				//OK.resize(1);
				cout<<" using "<<OK[0].name<<endl;
			}
		}
	}
	return 0;
}
