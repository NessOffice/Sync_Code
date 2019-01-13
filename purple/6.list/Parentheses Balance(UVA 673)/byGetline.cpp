#include <iostream>
#include <stack>
using namespace std;
const int maxn = 128 + 2;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string line;
	int n;
	while(cin>>n)
	{
		getline(cin, line);
		while(n--)
		{
			getline(cin, line);
			stack<char> s;
			bool ok = true;
			for(int i = 0;line[i] != '\0' && ok;i++)
			{
				if(line[i] == '(' || line[i] == '[') s.push(line[i]);
				else if(!s.empty())
				{
					if(line[i] == ']' && s.top() == '(') ok = false;
					if(line[i] == ')' && s.top() == '[') ok = false;
					s.pop();
				}else ok = false;
			}
			if(!s.empty()) ok = false;
			cout<<(ok ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
