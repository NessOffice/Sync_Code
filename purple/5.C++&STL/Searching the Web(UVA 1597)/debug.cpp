#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("out.txt","r",stdin);
	string str;
	int cnt = 0, line = 0;
	int target = 35;
	while(getline(cin, str))
	{
		if(str[0] == '=') cnt++;
		line++;
		if(line == target) break;
	}
	cout<<cnt;
	return 0;
}
