#include <iostream>
#include <vector> 
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> cnt;
vector<string> words;
string Standrize(string s)
{
	for(int i=0;i<s.length();i++)
		s[i]=tolower(s[i]);
	sort(s.begin(),s.end());
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;
	while(cin>>s)
	{
		if(s[0]=='#') break;
		words.push_back(s);
		string r;
		r=Standrize(s);
		if(!cnt.count(r)) cnt[r]=1;
		else cnt[r]=0;
	}
	sort(words.begin(),words.end());
	for(int i=0;i<words.size();i++)
		if(cnt[Standrize(words[i])])
			cout<<words[i]<<endl;
	return 0;
}
