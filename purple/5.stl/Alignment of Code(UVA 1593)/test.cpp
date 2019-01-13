#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>
using namespace std;
void print(string str, int len)
{
	int lenstr = str.length();
	cout<<str;
	for(int i = len;i > lenstr;i--)
		cout<<' ';
}
int main(){
	const int maxn = 1000 + 10; 
	vector<string> codes[maxn];
	vector<int> len;
	string line;
	int i = 0, j = 0;
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(getline(cin,line))
	{
		string word;
		stringstream ss(line);
		j = 0;
		while(ss >> word)
		{
			codes[i].push_back(word);
			if(len.size() <= j) len.push_back(word.length());
			if(word.length() > len[j]) len[j] = word.length();
			j++;
		}
		i++;
	}
	for(int j = 0;j < i;j++)
	{
		int sizes = codes[j].size();
		for(int k = 0;k < sizes;k++)
		{
			if(k == sizes - 1) cout<<codes[j][k];
			else print(codes[j][k], len[k] + 1);
		}
		cout<<endl;
	}
	return 0;
}
