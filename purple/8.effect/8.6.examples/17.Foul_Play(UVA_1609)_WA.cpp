#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1024 + 10;
char table[maxn][maxn];
int main()
{
	     freopen("in.txt", "r", stdin);
	     freopen("o1.txt", "w", stdout);
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 1;i <= n;i++)
			scanf("%s", table[i]+1);
		vector<int> win, lose, rest;
		for(int i = 2;i <= n;i++)
			if(table[1][i] == '1') win.push_back(i);
			else lose.push_back(i);
		for(int i = 1;i < n;i <<= 1)
		{
			rest.clear();
			vector<int> win2, lose2;
			//phase 1
			for(int j = lose.size()-1;j >= 0;j--)
			{
				bool match = false;
				for(int k = win.size()-1;k >= 0 && !match;k--)
					if(win[k] > 0 && table[win[k]][lose[j]] == '1')
					{
						printf("%d %d\n", win[k], lose[j]);
						win2.push_back(win[k]);
						win[k] = 0;
						match = true;
					}
				if(!match) rest.push_back(lose[j]);
			}
			//phase 2
			bool first = true;
			for(int j = win.size()-1;j >= 0;j--)
			if(win[j] > 0)
			{
				if(first){printf("1 %d\n", win[j]);first = 0;}
				else rest.push_back(win[j]);
			}
			//phase 3
			for(int j = rest.size()-1;j >= 1;j -= 2)
			{
				if(table[rest[j]][rest[j-1]]){
					printf("%d %d\n", rest[j], rest[j-1]);
					if(table[1][rest[j]]) win2.push_back(rest[j]);
					else lose2.push_back(rest[j]);
				}else{
					printf("%d %d\n", rest[j-1], rest[j]);
					if(table[1][rest[j-1]]) win2.push_back(rest[j-1]);
					else lose2.push_back(rest[j-1]);
				}
			}
			win = win2;
			lose = lose2;
		}
	}
	return 0;
}
