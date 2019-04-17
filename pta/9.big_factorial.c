#include <stdio.h>
#include <time.h>
typedef long long LL;
const LL MOD = 1e14;
LL res[40000], len = 1;
int main()
{
	clock_t begin, end;
	begin = clock();
	res[0] = 1;
	for(int i = 1;i <= 10000;i++)
	{
		for(int j = len-1;j >= 0;j--)
			res[j] *= i;
		for(int j = 0;j < len;j++)
		{
			if(res[j] >= MOD)
			{
				if(j == len-1) len++;
				res[j+1] += res[j] / MOD;
				res[j] %= MOD;
			}
		}
	}
	for(int i = len-1;i >= 0;i--)
	{
		if(i == len-1) printf("%lld", res[i]);
		else printf("%06lld", res[i]);
	}
	end = clock();
	printf("\ntime: %.4lf", (double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}