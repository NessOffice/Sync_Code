#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int abc, def, ghi;
	for (abc = 123; abc<=329;abc++)
	{
		def = 2*abc, ghi = 3*abc;
		bool visit[10] = {false};
		visit[abc/100] = visit[abc/10%10] = visit[abc%10] = true;
		visit[def/100] = visit[def/10%10] = visit[def%10] = true;
		visit[ghi/100] = visit[ghi/10%10] = visit[ghi%10] = true;
		bool flag = true;
		for(int i = 1;i <= 9 && flag;i++)
			if(visit[i] != true)
				flag = false;
		if(flag)
			cout<<abc<<' '<<def<<' '<<ghi<<endl;
	}
	return 0;
}
