#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register
using namespace std;
typedef long long LL;
const int maxn = 12;
const int MAXSTATE = (1<<12);
const int MOD = 1e8;
int f[maxn][MAXSTATE], field[maxn];
bool state_available[MAXSTATE];
int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &m, &n);
	for(int i = 0;i < m;i++)
	for(int j = 0;j < n;j++)
	{
		int grid;
		scanf("%d", &grid);
		field[i] = 2*field[i] + grid;
	}
	for(int st = 0;st < MAXSTATE;st++)
		state_available[st] = ((st&(st<<1)) == 0 && (st&(st>>1)) == 0);
	for(int st = 0;st < MAXSTATE;st++)
	{
		if(state_available[st] == false) continue;
		f[0][st] = (((st & field[0]) == st) ? 1 : 0);
	}
	for(int i = 1;i < m;i++)
	for(int st1 = 0;st1 < MAXSTATE;st1++)
		if(state_available[st1] && ((st1 & field[i]) == st1))
		for(int st2 = 0;st2 < MAXSTATE;st2++)
			if(state_available[st2] && ((st2 & field[i-1]) == st2))
			if((st1 & st2) == 0)
				f[i][st1] = (f[i][st1] + f[i-1][st2]) % MOD;
	for(int st = 0;st < MAXSTATE;st++)
		ans = (ans + f[m-1][st]) % MOD;
	printf("%d", ans);
	return 0;
}
