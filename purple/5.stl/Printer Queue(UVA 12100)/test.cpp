#include <iostream>
#include <map>
#include <queue> 
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		queue<int> printQ;
		map<int, int> fre;
		int prior = 0, temp, search, len, t, i;
		cin>>len>>search;
		for(i = 0;i < len;i++)
		{
			cin>>temp;
			printQ.push(temp);
			if(temp > prior) prior = temp;
			fre[temp]++;
		}
		i = t = 0;
		while(1)
		{
			temp = printQ.front();
			printQ.pop();
			if(temp == prior)
			{
				fre[prior]--;
				while(fre[prior] == 0 && prior >= 0)
					prior--;
				t++;
				if(i == search)
				{
					cout<<t<<endl;
					break;
				}
			}
			else
			{
				printQ.push(temp);
				if(i == search)
				{
					search = printQ.size() - 1;
					i = -1;
				}
			}
			i++;
		}
	}
	return 0;
}
