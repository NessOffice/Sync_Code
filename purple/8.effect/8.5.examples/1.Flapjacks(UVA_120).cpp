#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn = 30 + 2;
int num[maxn], n;
void flip(int p)
{
	printf("%d ", n - p);
	for(int i = 0;i < p - i;i++)
		swap(num[i], num[p-i]);
}
int main()
{
//	 freopen("in.txt", "r", stdin);
//	 freopen("out.txt", "w", stdout);
	string s;
	while(getline(cin, s))
	{
		printf("%s\n", s.c_str());
		n = 0;
		stringstream ss(s);
		while(ss >> num[n]) n++;
		for(int i = n-1;i >= 0;i--)
		{
			int p = max_element(num, num + i+1) - num;
			if(p == i) continue;
			if(p) flip(p);
			flip(i);
		}
		printf("0\n");
	}
	return 0;
}
