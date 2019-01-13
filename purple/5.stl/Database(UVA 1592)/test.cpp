#include <cstdio>
#include <string> 
#include <cstring> 
#include <map>
#include <algorithm>
using namespace std;
map<string, int> IDCache;
map<int, long long> ID2Cache;
const int rMax = 10000 + 10;
const int cMax = 10 + 2;
int IDnum;
int dataBase[rMax][cMax];
void FindDup(int r, int c)
{
	for(int i = 0;i < c;i++)
	for(int j = i + 1;j < c;j++)
	{
		ID2Cache.clear();
		for(int k = 0;k < r;k++)
		{//here the range of ID2 is limited 
			long long ID2 = dataBase[k][i] * 1000000 + dataBase[k][j];
			if(ID2Cache.count(ID2))
			{
				printf("NO\n");
				int r1 = ID2Cache[ID2];
				printf("%d %d\n",r1+1,k+1);
				printf("%d %d\n",i+1,j+1);
				return;//this shit problem requires only ONE solution
			}
			else ID2Cache[ID2] = k;
		}
	}
	printf("YES\n");
}
int ReadSize(int &r, int &c)
{
	char ch;
	int flag = 0;
	while(ch = getchar())
	{
		if(ch == EOF) return 0;
		if(ch == ' ' || ch == '\r' || ch == '\n')
		{
			if(flag) break;
			else flag++;
		}
		else
		{
			if(!flag)
			{
				r *= 10;
				r += (ch - '0');
			}
			else
			{
				c *= 10;
				c += (ch - '0');
			}
		}
	}
	return 1;
}
string ReadData()
{
	string temp;
	char ch;
	while((ch = getchar())!=EOF)
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
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int r = 0,c = 0;
	while(ReadSize(r,c))
	{
		memset(dataBase,0,sizeof(dataBase));
		IDnum = 0;
		IDCache.clear();
		for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++)
			dataBase[i][j] = ID(ReadData());
		FindDup(r,c);
		r = c = 0;
	}
	return 0;
}
