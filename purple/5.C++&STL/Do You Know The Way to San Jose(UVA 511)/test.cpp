#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct MAP
{
	string name;
	double x1,y1,x2,y2;
	double w,h,r,a,l;
	pair<double, double> c;
	
	bool operator < (const MAP &b) const
	{
		if(l != b.l) return l < b.l;
	} 
};
struct mult
{
	double x,y;
};
vector<int> level;
vector<MAP> maps;
map<string, mult> locations;
bool cmp(MAP m1, MAP m2)
{
	return m1.a > m2.a;
}
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
void ReadMaps()
{
	MAP newMap;
	string mapName;
	double x1,y1,x2,y2,w,h,xc,yc,r,a;
	cin>>mapName;
	while(cin>>mapName)
	{
		if(mapName == "LOCATIONS") break;
		newMap.name = mapName;
		cin>>x1>>y1>>x2>>y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		newMap.x1 = x1, newMap.y1 = y1;
		newMap.x2 = x2, newMap.y2 = y2;
		newMap.xc = (x1 + x2) / 2;
		newMap.yc = (y1 + y2) / 2;
		newMap.w = (x1 - x2);
		newMap.h = (y1 - y2);
		newMap.r = h / w;
		newMap.a = w * h;
		maps.push_back(newMap);
	}
	sort(maps.begin(), maps.end(), cmp);
	GetLevel();
}
void ReadLocations()
{
	string localName;
	double x,y;
	while(cin>>localName)
	{
		if(localName == "REQUESTS") break;
		cin>>x>>y;
		mult newMult;
		newMult.x = x, newMult.y = y;
		locations[localName] = newMult;
	}
}
bool cover(int i, double x, double y)
{
	double x1,x2,y1,y2;
	x1 = maps[i].x1, x2 = maps[i].x2;
	y1 = maps[i].y1, y2 = maps[i].y2;
	if(x1 <= x && x <= x2)
	if(y1 <= y && y <= y2)
		return true;
	return false;
}
void rOut(string name, int level, int flag)
{
	cout<<name<<" at detail level "<<level;
	if(flag == -1) cout<<" unknown locaton\n";
	else cout<<" using "<<maps[flag].name<<endl;
}
double dis(int i, double x, double y)
{
	double xc = maps[i].xc;
	double yc = maps[i].yc;
	return sqrt((x-xc)*(x-xc) + (y-yc)*(y-yc));
}
bool cmp1(int i, int j)
{
	;
}
void Sift(vector<int>& OK, int x, int y)
{
	int sifter = 0;
	while(OK.size() > 1)
	{
		int len = OK.size();
		if(sifter == 0)
		{
			sort(OK.begin(), OK.end(), cmp1);
			for(int i = 1;i < len;i++)
			{
				if(dis(i, x, y) != dis(i - 1, x, y))
				{
					OK.resize(i);
					break;
				}
			}
		}
		if(sifter == 1)
		{
			;
		}
		if(sifter == 2)
		{
			;
		}
		sifter++;
	}
}
void ReadRequests()
{
	string rName;
	int rLevel;
	while(cin>>rName)
	{
		vector<int> OK;
		cin>>rLevel;
		if(rName == "END") break;
		if(!locations.count(rName))
		{
			rOut(rName, rLevel, -1);
		}
		else
		{
			double x,y;
			x = locations[rName].x;
			y = locations[rName].y;
			int start = level[rLevel], finish = level[rLevel + 1];
			for(int i = start;i < finish;i++)
			{
				if(cover(i, x, y)) OK.push_back(i);
			}
			switch(OK.size())
			{
				case 0:break;
				case 1:rOut(rName, rLevel, OK[0]);break;
				default:break;//Sift(OK,x,y);rOut(rName, rLevel, OK[0]);break;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ReadMaps();
	ReadLocations();
	ReadRequests();
	return 0;
}
