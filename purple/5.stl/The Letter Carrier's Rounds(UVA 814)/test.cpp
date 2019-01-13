#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<string> userCache;
void separate(string str, string& uName, string& mtaName)
{
	int p = str.find('@');
	uName = str.substr(0,p);
	mtaName = str.substr(p+1);
}
void SMTP()
{
	while(1)
	{
		string sender,sName,sAddress;
		string recipent,rName,rAddress;
		string temp,data;
		map<string, vector<string> > dest;
		
		vector<string> Recipent;
		getline(cin,temp);//sender and recipents
		if(temp[0] == '*') return;
		stringstream ss(temp);
		ss >> sender;
		separate(sender,sName,sAddress);
		while(ss >> recipent)
		{
			Recipent.push_back(recipent);
			separate(recipent,rName,rAddress);
			dest[rAddress].push_back(recipent);
		}
		getline(cin,temp);//eat '*'
		while(getline(cin,temp))//read content
		{
			if(temp[0] == '*') break;
			data += ("     " + temp + '\n');
		}
		map<string, int> access;
		for(int i = 0;i < Recipent.size();i++)//output
		{
			separate(Recipent[i],rName,rAddress);
			if(access[rAddress]) continue;
			access[rAddress] = 1;
			vector<string> mta2 = dest[rAddress];
			cout<<"Connection between "<<sAddress<<" and "<<rAddress<<endl;
			cout<<"     HELO "<<sAddress<<"\n     250\n";
			cout<<"     MAIL FROM:<"<<sender<<">\n     250\n";
			int ok = 0;
			map<string ,int> userUnique;
			for(int j = 0;j < mta2.size();j++)
			{
				if(userUnique[mta2[j]]) continue;
				userUnique[mta2[j]] = 1;
				separate(mta2[j], rName, rAddress);
				cout<<"     RCPT TO:<"<<mta2[j];
				if(userCache.count(mta2[j]))
				{
					cout<<">\n     250\n";
					ok = 1;
				}
				else cout<<">\n     550\n";
			}
			if(ok)
			{
				cout<<"     DATA\n     354\n"<<data<<"     .\n     250\n";
			}
			cout<<"     QUIT\n     221\n";
		}
	}
}
void print()
{
	for(set<string>::iterator it = userCache.begin();it != userCache.end();it++)
		cout<<*it<<endl;
}
void ReadMTA(string str)
{
	string cityName,userName,mta;
	int userNumber;
	stringstream ss(str);
	ss >> mta >> cityName >> userNumber;
	for(int i = 0;i < userNumber;i++)
	{
		ss >> userName;
		userCache.insert(userName + "@" + cityName);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string temp;
	int flag = 0;
	while(getline(cin,temp))
	{
		if(temp[0] == '*') flag++;
		if(flag == 0) ReadMTA(temp);
		else
		{
			SMTP();
			//print();
			break;
		}
	}
	return 0;
}
