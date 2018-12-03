#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line;
	while(getline(cin, line))
	{
		deque<string> text;
		int len = line.length(), flag = 1;
		string temp = "";
		for(int i = 0;i < len;i++)
		{
			char ch = line[i];
			if(ch == '[' || ch == ']')
			{
				if(temp != "")
				{
					if(flag) text.push_back(temp);
					else text.push_front(temp);
					temp = "";
				}
				flag = line[i] == ']' ? 1 : 0;
			}
			else temp += ch;
		}
		if(temp != "")
			if(flag) text.push_back(temp);
			else text.push_front(temp);
		len = text.size();
		for(int i = 0;i < len;i++)
			cout<<text[i];
		cout<<endl;
	}
	return 0;
}
