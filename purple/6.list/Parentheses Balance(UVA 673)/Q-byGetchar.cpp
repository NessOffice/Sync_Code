#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 128 + 2;
char line[maxn];
int ReadLine()
{
	int len = 0;
	char ch;
	while(ch = (getchar()))
	{
		if(ch == '\r' || ch == '\n' || ch == EOF || ch == ' ') return len;
		else line[len++] == ch;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char line[maxn];
	int n;
	while(scanf("%d", &n))
	{
		getchar();
		while(n--)
		{
			int len = ReadLine();
			stack<char> s;
			bool ok = true;
			for(int i = 0;i < len && ok;i++)
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
			if(ok) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
