#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Building
{
	int ID;
	double x, y, w, d, h;
	double x1, x2;
};
vector<Building> b;
vector<double> X;
int n;
int cmp(Building t1, Building t2)
{
	return t1.x==t2.x?t1.y<t2.y:t1.x<t2.x;
}
bool cover(int i, double x)
{
	return (b[i].x1 <= x && b[i].x2 >= x);
}
bool Visible(int i, double x)
{
	if(!cover(i, x)) return false;
	for(int j = 0;j < n;j++)
	{
		if(cover(j, x) 
		&& b[j].h >= b[i].h
		&& b[j].y < b[i].y)
				return false;
	}
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase = 0;
	while(scanf("%d",&n) && n)
	{
		b.clear();
		X.clear();
		for(int i = 0;i < n;i++)
		{
			Building t;
			scanf("%lf%lf%lf%lf%lf",&t.x,&t.y,&t.w,&t.d,&t.h);
			t.ID = i + 1;
			t.x1 = t.x;
			t.x2 = t.x1 + t.w;
			b.push_back(t);
		}
		sort(b.begin(),b.end(),cmp);
		for(int i = 0;i < n;i++)
		{
			X.push_back(b[i].x1);
			X.push_back(b[i].x2);
		}
		sort(X.begin(), X.end());
		vector<double>::iterator it = unique(X.begin(), X.end());
		X.erase(it, X.end());
		int len = X.size();
		
		if(kase++) printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d",kase, b[0].ID);
		for(int i = 1;i < n;i++)
		{
			bool vis = false;
			for(int j = 0;j + 1 < len;j++)
			{
				if(Visible(i, (X[j] + X[j + 1])/2)){vis = true;break;}
			}
			if(vis) printf(" %d", b[i].ID);
		}
		printf("\n");
	}
	return 0;
}
