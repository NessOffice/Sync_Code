#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10000 * 2 + 5;
int ID;
map<int, int> yCache;
vector<int> xCache[maxn];
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,x,y,sym;
	cin>>n;
	while(n--)
	{
		yCache.clear();
		ID = 0;
		for(int i = 0;i < maxn;i++)
			xCache[i].clear();
		cin>>m;
		while(m--)
		{
			cin>>x>>y;
			if(!yCache.count(y)) yCache[y] = ID++;
			xCache[yCache[y]].push_back(x);
		}
		int sym, flag = 1, flag2 = 1;
		for(int i = 0;i < ID;i++)
		{
			int len = xCache[i].size();
			sort(xCache[i].begin(),xCache[i].end());
			for(int j = len - 1;j >= 0;j--)
			{
				if(flag)
				{
					sym = (xCache[i][j] + xCache[i][len-1 - j]);
					flag = 0;
				}
				if(sym != (xCache[i][j] + xCache[i][len-1 - j]))
				{
					flag2 = 0;
					break;
				}
			}
		}
		if(flag2) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
