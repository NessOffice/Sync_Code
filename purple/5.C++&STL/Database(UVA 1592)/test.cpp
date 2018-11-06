#include <iostream>
#include <string> 
#include <cstring> 
#include <map>
#include <algorithm>
using namespace std;
map<string, int> IDCache;
const int rMax = 10000 + 10;
const int cMax = 10 + 2;
int IDnum;
string ReadData()
{
	string temp;
	char ch;
	while(ch = getchar())
	{
		if(ch == '\r' || ch == '\n' || ch == ',')
			break;
		temp += ch;
	}
	return temp;
}
int ID(string str)
{
	if(IDCache.count(str)) return IDCache[str];
	return IDCache[str] = IDnum++;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);// what's wrong?
	//freopen("out.txt","w",stdout);
	int dataBase[rMax][cMax];
	int r,c;
	string temp;
	while(cin>>r>>c)
	{
		getchar(); 
		memset(dataBase,0,sizeof(dataBase));
		IDnum = 0;
		IDCache.clear();
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j < c;j++)
			{
				dataBase[i][j] = ID(ReadData());
				cout<<dataBase[i][j]<<' '; 
			}
			cout<<endl;
		}
	}
	return 0;
}
