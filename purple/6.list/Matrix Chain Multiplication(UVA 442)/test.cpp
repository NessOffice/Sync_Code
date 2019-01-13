#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, r, c;
	char key;
	map<char, pair<int, int> > matrix;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>key>>r>>c;
		matrix[key] = make_pair(r, c);
	}
	string exp;
	while(cin>>exp)
	{
		stack<pair<int, int> > s;
		int ans = 0, len = exp.length();
		bool error = false;
		for(int j = 0;j < len;j++)
		{
			char ch = exp[j];
			if(isalpha(ch)) s.push(matrix[ch]);
			else if(ch == ')')
			{
				pair<int, int> m2 = s.top();s.pop();
				pair<int, int> m1 = s.top();s.pop();
				if(m1.second != m2.first){error = true;break;}
				ans += m1.first * m1.second * m2.second;
				s.push(make_pair(m1.first, m2.second));
			}
		}
		if(error) cout<<"error\n";
		else cout<<ans<<endl;
	}
	return 0;
}
