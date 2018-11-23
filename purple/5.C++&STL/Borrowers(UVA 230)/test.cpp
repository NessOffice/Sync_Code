#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct book
{
	string name;
	string auther;
	int status;
};
bool cmp(book b1, book b2)
{
	if(b1.auther == b2.auther) return b1.name<b2.name;
	return b1.auther<b2.auther; 
}
vector<book> shelf;
int findBook(string name)
{
	int len = shelf.size();
	for(int i = 0;i < len;i++)
	{
		if(shelf[i].name == name) return i;
	}
}
void Process()
{
	string line;
	string name;
	while(getline(cin,line))
	{
		char cmd = line[0];
		if(cmd == 'E') return;
		int ans = line.find("\"");
		if(ans > 0)
		{
			name = line.substr(ans);
		}
		if(cmd == 'B')
		{
			int i = findBook(name);
			shelf[i].status = 0;
		}
		else if(cmd == 'R')
		{
			int i = findBook(name);
			shelf[i].status = -1;
		}
		else if(cmd == 'S')
		{
			int len = shelf.size(), flag = -1;
			for(int i = 0;i < len;i++)
			{
				if(shelf[i].status == -1)
				{
					string record;
					record = "Put " + shelf[i].name;
					if(flag == -1) record += " first";
					else record += (" after " + shelf[flag].name);
					cout<<record<<endl;
					shelf[i].status = 1;
				}
				if(shelf[i].status) flag = i;
			}
			cout<<"END\n";
		}
	}
}
void ReadBook()
{
	string line, name, auther;
	while(getline(cin,line))
	{
		int ans = line.rfind("\"");
		if(ans == -1) break;
		else
		{
			book newbook;
			name = line.substr(0,ans + 1);
			auther = line.substr(ans);
			newbook.name = name;
			newbook.auther = auther;
			newbook.status = 1;
			shelf.push_back(newbook);
		}
	}
	sort(shelf.begin(),shelf.end(),cmp);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ReadBook();
	Process();
	return 0;
}
