#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
void go(int mask[], int &now, int n)
{
	now++;
	while(now > n || mask[now])
	{
		now++;
		if(now > n)
			now = 1;
	}
}
int solve(int step, int loc, int n)
{
	// printf("[DEBUG]%d, %d, %d\n", step, loc, n);
	if(n > step){
		if((loc-1) % step == 0)
			return (loc-1)/step+1;
		int k = (n-1)/step;
		int loc_new;
		if(k*step+1 > loc)
			loc_new = loc+n-(k*step+1)-((loc-1)/step+1)+1;
		else
			loc_new = loc-k*step;
		return k + solve(step, loc_new , n-k);
	}else{
		int mask[12] = {0}, now = 1;
		for(int rnd = 1;;rnd++)
		{
			// printf("[DEBUG]%d\n", now);
			mask[now] = 1;
			if(now == loc) return rnd;
				for(int i = 0;i < step;i++)
					go(mask, now, n);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, q, num;
		scanf("%d%d%d", &n, &m, &q);
		while(q--)
		{
			scanf("%d", &num);
			printf("%d\n", solve(m+1, num, n));
		}
	}
	return 0;
}
/*
10
10 3 10
2
*/
