#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
int n;
double totalMoney, share[72];
struct playerData
{
	string name;
	int score[5];
	int DQ;
	int amateur; 
};
vector<playerData> player;
void PrintPlayer()
{
	for(int i = 0;i < player.size();i++)
	{
		cout<<player[i].name<<' ';
		if(player[i].DQ == -1)
		{
			for(int j = 0;j < 4;j++)
				cout<<player[i].score[j]<<' ';
		}
		else for(int j = 0;j <= player[i].DQ;j++)
				cout<<player[i].score[j]<<' ';
		cout<<player[i].amateur<<endl;
	}
}
void ReadMoney()
{
	
}
void ReadPlayer()
{
	string line,temp;
	getline(cin,line);
	stringstream ss(line);
	sscanf(line.c_str(),"%d",&n);
	for(int i = 0;i < n;i++)
	{
		playerData newPlayer;
		newPlayer.DQ = -1;
		newPlayer.amateur = 0;
		int flag = -1;
		getline(cin,line);
		stringstream ss(line);
		while(ss >> temp)
		{
			if(isdigit(temp[0]))
			{
				flag++;
				int score;
				sscanf(temp.c_str(),"%d",&score);
				newPlayer.score[flag]
					= score;
			}
			if(temp == "DQ")
			{
				newPlayer.DQ = flag;
				break;
			}
			if(flag == -1)
			{
				if(newPlayer.name != "") newPlayer.name += ' ';
				newPlayer.name += temp;
				if(temp[temp.length() - 1] == '*')
					newPlayer.amateur = 1; 
			}
		}
		player.push_back(newPlayer);
	}
}
int main(){
	freopen("in.txt","r",stdin);
	ReadMoney();
	ReadPlayer();
	//PrintPlayer();
	return 0;
}
