#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct COMMAND{
	int type;
	char var;
	int value;
};
struct PROGRAM{
	COMMAND cmd[30];
	int index;
}programs[12];
int n, dt[6], q, v[30] = {0}, lock = -1;
queue<int> blocked;
deque<int> ready;
void test(int n)
{
	for(int i = 0;i < n;i++)
	{
		int j = 0;
		do
		{
			int type = programs[i].cmd[j].type;
			cout<<programs[i].cmd[j].type;
			if(type <= 1) cout<<" "<<programs[i].cmd[j].var;
			if(type == 0) cout<<" "<<programs[i].cmd[j].value;
			cout<<endl;
		}while(programs[i].cmd[j++].type != 4);
	}
}
void ReadProgram()
{
	cin>>n;for(int i = 0;i < 5;i++) cin>>dt[i];cin>>q;
	string temp;
	for(int i = 0;i < n;i++)
	{
		ready.push_back(i);
		programs[i].index = 0;
		int j = 0, value, type;
		char var;
		while(cin>>temp)
		{
			if(temp.length() == 1)
			{
				var = temp[0];
				cin>>temp>>value;
				type = 0;
			}
			else
				switch(temp[0])
				{
					case 'p':type = 1;cin>>temp;var = temp[0];break;
					case 'l':type = 2;break;
					case 'u':type = 3;break;
					case 'e':type = 4;break;
				}
			programs[i].cmd[j].type = type;
			if(type <= 1) programs[i].cmd[j].var = var;
			if(type == 0) programs[i].cmd[j].value = value;
			if(type == 4) break;
			j++;
		}
	}
}
void RunProgram()
{
	while(!ready.empty())
	{
		int run = ready.front();
		ready.pop_front();
		int t = 0, type, flag = 1;
		while(t < q)
		{
			int index = programs[run].index;
			type = programs[run].cmd[index].type;
			switch(type)
			{
				case 0:v[programs[run].cmd[index].var - 'a'] = programs[run].cmd[index].value;break;
				case 1:cout<<run+1<<": "<<v[programs[run].cmd[index].var - 'a']<<endl;break;
				case 2:
					if(lock != -1){blocked.push(run);flag = 0;}
					else lock = run;
					break;
				case 3:
					lock = -1;
					if(!blocked.empty()){ready.push_front(blocked.front());blocked.pop();}
					break;
				case 4:flag = 0;break;
			}
			t += dt[type];
			if(flag == 0) break;
			programs[run].index++;
		}
		if(flag) ready.push_back(run);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m, first = 0;cin>>m;
	while(m--)
	{
		lock = -1;
		for(int i = 0;i < 30;i++) v[i] = 0;
		ready.clear();
		blocked = queue<int>();
		if(first++) cout<<endl;
		ReadProgram();
		//test(n);
		RunProgram();
	}
	return 0;
}
