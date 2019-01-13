#include <iostream>
#include <string>
#include <map>
using namespace std;
map<long long, int> base;
long long total, ans;
string expr;
bool treeDFS(int begin, int end, int depth)//end不取等不可以吗？
{
	if(expr[begin] == '['){
		int pos = 0;
		for(int i = begin + 1;i < end;i++)
		{
			if(expr[i] == '[') pos++;
			if(expr[i] == ']') pos--;
			if(!pos && expr[i] == ',')//利用pos来建树，值得学习
			{
				treeDFS(begin + 1, i - 1, depth + 1);
				treeDFS(i + 1, end - 1, depth + 1);
				break;
			}
		}
	}else{
		long long value = 0;
		for(int i = begin;i <= end;i++)
			value = value * 10 + expr[i] - '0';
		base[value<<depth]++, total++;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;cin>>n;
	while(n--)
	{
		cin>>expr;
		total = ans = 0;
		base.clear();
		treeDFS(0, expr.size() - 1, 0);
		for(map<long long, int>::iterator it = base.begin();it != base.end();it++)
			if(it->second > ans) ans = it->second;
		cout<<(total - ans)<<endl;
	}
	return 0;
}
