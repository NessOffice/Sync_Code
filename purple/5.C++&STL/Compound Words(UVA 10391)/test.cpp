#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> dict;
void search(string str)
{
	for(int i = str.length() - 1;i > 0;i--)
	{
		string head = str.substr(0,i);
		string tail = str.substr(i);
		if(dict.count(head))
		if(dict.count(tail))
		{
			cout<<str<<endl;
			return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string temp;
	while(cin>>temp)
		dict.insert(temp);
	for(set<string>::iterator it = dict.begin();it != dict.end();it++)
		search(*it);
	return 0;
}
