#include <cstdio>
#include <map>
using namespace std;
const int maxn = 100 + 5;
struct Transition{
	map<int, int> in;
	map<int, int> out;
};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int NT, NP, NF, kase = 0;
	int token[maxn];
	while(scanf("%d", &NP) && NP)
	{
		for(int i = 1;i <= NP;i++)
			scanf("%d", &token[i]);
		scanf("%d", &NT);
		Transition t[NT]; 
		for(int i = 0;i < NT;i++)
		{
			int temp;
			while(scanf("%d", &temp) && temp)
			{
				if(temp < 0)
				{
					if(!t[i].in.count(-temp)) t[i].in[-temp] = 0;
					t[i].in[-temp]++;
				}
				else
				{
					if(!t[i].out.count(temp)) t[i].out[temp] = 0;
					t[i].out[temp]++;
				}
			}
		}
		scanf("%d", &NF);
		bool dead;
		map<int, int>::iterator it;
		for(int i = 0;i < NF;i++)
		{
			dead = true;
			for(int j = 0;j < NT;j++)
			{
				bool able = true;
				for(it = t[j].in.begin();it != t[j].in.end() && able;it++)
					if(it->second > token[it->first]) able = false;
				if(able)
				{
					for(it = t[j].in.begin();it != t[j].in.end();it++)
						token[it->first] -= it->second;
					for(it = t[j].out.begin();it != t[j].out.end();it++)
						token[it->first] += it->second;
					dead = false;
					break;
				}
			}
			if(dead){printf("Case %d: dead after %d transitions\n", ++kase, i);break;}
		}
		if(!dead) printf("Case %d: still live after %d transitions\n", ++kase, NF);
		printf("Places with tokens:");
		for(int i = 1;i <= NP;i++)
			if(token[i]) printf(" %d (%d)", i, token[i]);
		printf("\n\n");
	}
	return 0;
}
