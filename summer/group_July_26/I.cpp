#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MOD = (1<<20);
inline int fun(int x){return (int)((487237LL * x + 1011807LL) % MOD);}
// bool odious[MOD+1];
int odious(int x)
{
	int digit = 0;
	while(x)
	{
		if(x & 1LL) digit++;
		x >>= 1LL;
	}
	if(digit & 1) return 1;
	else return -1;
}
int main()
{
	int x = 0, n, hash_val[66];
	for(int i = 0;i <= 60;i++)
	{
		scanf("%d", &n);
		printf("%d\n", 1);
		// fflush(stdin);
		fflush(stdout);
		hash_val[i] = n;
	}
	for(x = 0;x < (1<<20);x++)
	{
		int xx = x, val = 160, i;
		for(i = 1;i <= 60;i++)
		{
			xx = fun(xx);
			val += odious(xx);
			if(val != hash_val[i]) break;
		}
		if(i > 60) break;
	}
	for(int i = 1;i <= 60;i++)
		x = fun(x);
	while(1)
	{
		scanf("%d", &n);
		if(n == -1) break;
		x = fun(x);
		if(odious(x)) printf("%d\n", n-1);
		else printf("1");
		// fflush(stdin);
		fflush(stdout);
	}
	return 0;
}
/*
1
2
2 2 3 3
4 4 5 5
*/
