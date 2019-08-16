#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = (1<<20);
LL fun(LL x)
{
	return (487237LL * x + 1011807LL) % MOD;
}
bool odious(LL x)
{
	LL digit = 0;
	while(x)
	{
		if(x & 1LL) digit++;
		x >>= 1LL;
	}
	return (digit & 1);
}
bool check(LL x, LL times)
{
	if(times == 0) return true;
	if(times == 1) return odious(x);
	return check(fun(x), times-1);
}
int code(int i, int j) {
	
}
LL win[10][10000], cnt[10][10000]; // win = 0, lose = 1
int main()
{
	for(LL i = 0;i < MOD;i++)
	{
		for(LL j = 0;j < 4;j++)
		{
			if(check(i,j)) {
				cnt[j][]
			}
		}
	}
	for(LL j = 0;j < 4;j++)
		for(LL k = 0;k < (1<<(j+1));k++)
			printf("%lld %lld: %lf\n", j, k, 1.0 * win[j][k] / cnt[j][k]);
	return 0;
}
/*
1
2
2 2 3 3
4 4 5 5
*/
