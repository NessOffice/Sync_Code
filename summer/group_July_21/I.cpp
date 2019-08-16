#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 5e3+5;
int rd(){int a;scanf("%d", &a);return a;}
int sg[maxn], state[maxn];
void calc_SG()
{
	memset(sg, -1, sizeof(sg));
	sg[0] = sg[1] = 0, sg[2] = 1;
	for(int i = 3;i < maxn;i++)
	{
		memset(state, 0, sizeof(state));
		for(int j = 0;j <= i-2;j++)
			state[sg[j]^sg[i-j-2]] = 1;
		for(int j = 0;sg[i] == -1;j++)
			if(state[j] == 0) sg[i] = j;
	}
}
int main()
{
	calc_SG();
	for(int T = rd();T;T--)
		printf("%s\n", sg[rd()] ? "First" : "Second");
	return 0;
}
