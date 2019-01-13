#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <set>
using namespace std;
set<string> delTerm;
set<string> newTerm;
set<string> editTerm;
map<string, string> dict;
void OutputUpdata(set<string>& change, char type)
{
	int first = 0;
	cout<<type;
	for(set<string>::iterator it = change.begin();it != change.end();it++)
	{
		if(first++) cout<<',';
		cout<<*it;
	}
	cout<<endl;
}
void DictOp(char type)
{
	int flag = 0, len;
	char ch;
	string key, value, line;
	getline(cin, line);
	len = line.length();
	for(int i = 0;i < len;i++)
	{
		ch = line[i];
		if(ch == '{' || ch == ' ') continue;
		if(key != "" && (ch == ',' || ch == '}'))
		{
			if(type == 'r')
			{
				delTerm.insert(key);
				dict[key] = value;
			}
			else
			{
				if(delTerm.count(key))
					delTerm.erase(key);
				if(!dict.count(key))
					newTerm.insert(key);
				else if(dict[key] != value)
					editTerm.insert(key);
			}
			key = value = "";
			flag++;
			continue;
		}
		if(ch == ':') flag++;
		if(flag % 2) value += ch;
		else key += ch;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string buf;
	int n;cin>>n;
	getline(cin, buf);
	while(n--)
	{
		DictOp('r');
		DictOp('u');
		int flag = 1;
		if(newTerm.size()){OutputUpdata(newTerm, '+');flag = 0;}
		if(delTerm.size()){OutputUpdata(delTerm, '-');flag = 0;}
		if(editTerm.size()){OutputUpdata(editTerm, '*');flag = 0;}
		if(flag) cout<<"No changes\n";
		dict.clear();
		delTerm.clear();
		newTerm.clear();
		editTerm.clear();
		cout<<endl;
	}
	return 0;
}
