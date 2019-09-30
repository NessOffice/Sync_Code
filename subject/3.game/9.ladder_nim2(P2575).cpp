#include <cstdio>
#include <cstring>
int rd(){int x;scanf("%d", &x);return x;}
bool mark[30];
int main()
{
	for(int T = rd();T;--T)
	{
		int ans1 = 0;
		for(int n = rd();n;--n)
		{
			int ans2 = 0, odd = 0, cnt = 0;
			memset(mark, 0, sizeof(mark));
			for(int m = rd();m;--m)
				mark[rd()] = true;
			for(int i = 20;~i;--i)
			{
				if(mark[i]){
					if(odd) cnt++;
				}else{
					ans2 ^= cnt;
					cnt = 0;
					odd ^= 1;
				}
			}
			ans2 ^= cnt;
			ans1 ^= ans2;
		}
		printf("%s\n", ans1 ? "YES" : "NO");
	}
	return 0;
}
