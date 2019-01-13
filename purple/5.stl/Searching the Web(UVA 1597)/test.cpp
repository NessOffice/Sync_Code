#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
struct Mult
{
	int num1, num2;
};
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	vector<string> a[maxn];
	map<string, vector<Mult> > words;
	string line;
	int n, q;
	cin>>n;
	getline(cin, line);
	for(int i = 0;i < n;i++)
	{
		int j = 0;
		while(getline(cin, line))
		{
			map<string, int> repeat;
			string line1, word;
			Mult newMult;
			if(line[0] == '*') break;
			a[i].push_back(line);
			
			int len0 = line.length();
			for(int k = 0;k < len0;k++)
			{
				if(isalpha(line[k]))
					line1 += (tolower(line[k]));
				else line1 += ' ';
			}
			stringstream ss(line1);
			newMult.num1 = i;
			newMult.num2 = j;
			while(ss>>word)
			{
				if(!repeat.count(word))
					words[word].push_back(newMult);
				repeat[word] = 1;
			}
			j++;
		}
	}
	cin>>q;
	getline(cin, line);
	for(int i = 0;i < q;i++)
	{
		getline(cin, line);
		stringstream ss(line);
		string temp;
		vector<string> term;
		
		int opType = 1;
		while(ss>>temp)
		{
			if(temp == "NOT") opType = 4;
			else if(temp == "AND") opType = 2;
			else if(temp == "OR") opType = 3;
			else term.push_back(temp);
		}
		
		int first = 0;
		if(opType == 4)
		{
			map<int, int> OK;
			int len = words[term[0]].size();//多少篇出现了该词 
			for(int j = 0;j < len;j++)
			{
				string word = term[0];
				int passage = words[word][j].num1;
				OK[passage] = 1;
			}
			for(int j = 0;j < n;j++)
				if(!OK.count(j))
				{
					if(first++) cout<<"----------\n";
					int len1 = a[j].size();
					for(int k = 0;k < len1;k++)
						cout<<a[j][k]<<endl;
				}
			if(first == 0) cout<<"Sorry, I found nothing.\n";
		}
		else
		{
			vector<int> OK[maxn];
			int len[2];
			map<int, int> flag[2];
			for(int k = 0;k < (opType == 1?1:2);k++)
			{
				
				len[k] = words[term[k]].size();
				for(int j = 0;j < len[k];j++)
				{
					string word = term[k];
					int p = words[word][j].num1;
					int s = words[word][j].num2;
					flag[k][p] = 1;
					OK[p].push_back(s);
				}
			}
			for(int j = 0;j < n;j++)
			{
				if(opType == 2)
					if(flag[0][j] == 0 || flag[1][j] == 0)
						continue;
				sort(OK[j].begin(), OK[j].end());
				vector<int>::iterator end_u =  unique(OK[j].begin(), OK[j].end());
				OK[j].erase(end_u, OK[j].end());
				int plen = OK[j].size();
				if(plen) if(first++) cout<<"----------\n";
				for(int k = 0;k < plen;k++)
				{
					cout<<a[j][OK[j][k]]<<endl;
				}
			}
			if(first == 0) cout<<"Sorry, I found nothing.\n";
		}
		cout<<"==========\n";
	}
	return 0;
}
