#include <iostream>
#include <string>
#include <map>
using namespace std;
map<long long, int> base;
long long total, ans;
string expr;
bool treeDFS(int begin, int end, int depth)
{
	if(expr[begin] == '['){
		int pos = 0;
		for(int i = begin + 1;i < end;i++)
		{
			if(expr[i] == '[') pos++;
			if(expr[i] == ']') pos--;
			if(!pos && expr[i] == ',')//利用pos来建树，值得学习
			{
				treeDFS(begin + 1, i, depth + 1);
				treeDFS(i + 1, end, depth + 1);
				break;
			}
		}
	}else{
		long long value = 0;
		for(int i = begin;i < end && expr[i] != ']';i++)
			value = value * 10 + expr[i] - '0';
		base[value<<depth]++, total++;
		if(base[value<<depth] > ans) ans++;
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;cin>>n;
	while(n--)
	{
		cin>>expr;
		total = ans = 0;
		base.clear();
		treeDFS(0, expr.size(), 0);
		cout<<(total - ans)<<endl;
	}
	return 0;
}
