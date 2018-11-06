#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void print(string str, char makeup, int len)
{
	cout<<str;
	for(int i=len-str.length();i>0;i--)
		cout<<makeup;
}
int main()
{
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	vector<string> fileName;
	string temp;
	int n,lenMax;
	while(cin>>n)
	{
		int r, c = 0;
		lenMax = 0;
		fileName.clear();
		print("",'-',60);
		cout<<endl;
		for(int i = 0;i < n;i++)
		{
			cin>>temp;
			lenMax = max(lenMax,int(temp.length()));
			fileName.push_back(temp);
		}
		sort(fileName.begin(), fileName.end());
		while(++c)
		{
			if(c*(lenMax+2)+lenMax>60)
				break;
		}
		r = (n - 1) / c + 1;
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j < c;j++)
			{
				int k = i + j*r;
				int flag = 2;
				if((j == c - 1) || (k + r >= n)) flag = 0;
				if(k < n) print(fileName[k],' ',lenMax + flag);
			}
			cout<<'\n';
		}
	}
	return 0;
}
