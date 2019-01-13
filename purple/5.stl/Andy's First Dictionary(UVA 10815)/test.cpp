#include <iostream>
#include <set> 
#include <string>
#include <sstream>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s,buf;
	set<string> dict;
	while(cin>>s)
	{
		for(int i=0;i<s.length();i++)
			if(isalpha(s[i])) s[i]=tolower(s[i]);
			else s[i]=' ';
		stringstream ss(s);
		while(ss>>buf) dict.insert(buf);
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
		cout<<*it<<endl;
	return 0;
}
