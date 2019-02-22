#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n && n)
	{
		string str[maxn], ans;
		for(int i = 0;i < n;i++)
			cin>>str[i];
		sort(str, str + n);
		ans = "";
		string str1 = str[n/2-1];
		string str2 = str[n/2];
		int len = 0, len1, len2;
		len1 = str1.length();
		len2 = str2.length();
		while(len < len1 && len < len2 && str1[len] == str2[len]){ans[len] = str1[len];len++;}
		if(len < len1)//ans != str1
		{
			if(len == len1 - 1) ans[len] = str1[len];
			else if(len < len2 - 1) ans[len] = str1[len] + 1;
			else
			{
				ans[len] = str1[len];len++;
				ans[len] = (len == len1 - 1 ? str1[len] : str1[len] + 1);
			}
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}
