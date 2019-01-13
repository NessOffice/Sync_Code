#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
const int maxn = 20000;
vector<int> relied[maxn];
vector<int> rely[maxn];
vector<int> installed;
int cnt = 0,cnt_ins = 0;
int ins[maxn] = {0};
map<string, int> comID;
map<int, string> components;
bool Needed(int com)
{
	int len = relied[com].size();
	for(int i = 0;i < len;i++)
		if(ins[relied[com][i]]) return true;
	return false;
}
void Install(int com, int type)
{
	if(ins[com] && type) cout<<"   "<<components[com]<<" is already installed.\n";
	if(ins[com]) return;
	int len = rely[com].size();
	for(int i = 0;i < len;i++)
		Install(rely[com][i], 0);
	ins[com] = type ? 1 : -1;
	cout<<"   Installing "<<components[com]<<endl;
	installed.push_back(com);
}
void Remove(int com, int type)
{
	if(type && ins[com] == 0){cout<<"   "<<components[com]<<" is not installed.\n";return;}
	if(Needed(com))
	{
		if(type)
			cout<<"   "<<components[com]<<" is still needed.\n";
		return;
	}
	if(type || ins[com] == -1)
	{
		ins[com] = 0;
		int len = installed.size();
		for(int i = 0;i < len;i++)
			if(installed[i] == com) installed.erase(installed.begin() + i);
		cout<<"   Removing "<<components[com]<<endl;
		len = rely[com].size();
		for(int i = 0;i < len;i++)
			if(ins[rely[com][i]])
				Remove(rely[com][i], 0);
	}
}
int ID(string str)
{
	if(comID.count(str)) return comID[str];
	components[cnt] = str;
	return comID[str] = cnt++;
}
int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	string line;
	while(getline(cin, line))
	{
		cout<<line<<endl;
		stringstream ss(line);
		string cmd, com1, com2;
		ss>>cmd;
		if(cmd[0] == 'E') break;
		ss>>com1;
		switch(cmd[0])
		{
			case 'D':
				while(ss>>com2)
				{
					relied[ID(com2)].push_back(ID(com1));
					rely[ID(com1)].push_back(ID(com2));
				}
				break;
			case 'I':Install(ID(com1), 1);break;
			case 'R':Remove(ID(com1), 1);break;
			case 'L':
				int len = installed.size();
				for(int i = 0;i < len;i++)
					cout<<"   "<<components[installed[i]]<<endl;
				break;
		}
	}
	return 0;
}
