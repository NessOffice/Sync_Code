#include <cstdio>
#include <cstring>
typedef long long LL;
int main()
{
	LL T, num;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &num);
		num--;
		num <<= 1;
		if((__builtin_popcountll(num) & 1) == 0)
			num++;
		printf("%lld\n", num);
	}
	return 0;
}