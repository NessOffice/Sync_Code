#include <cstdio>
#include <cstring>
#include <cctype>
typedef long long LL;
LL odious(LL num)
{
	if(num == 0 || num == 1) return num;
	LL two = 1LL;
	while(two*2LL < num)
		two <<= 1;
	LL num_new = num - two - 1;
	two <<= 1;
	if(num_new == 0) // 5, 9, 17, ...
		return two;
	LL two_new = 1LL;
	while(two_new <= num_new)
		two_new <<= 1;
	LL odious_new = 0;
	if(two_new)
		odious_new = odious(num_new - (two_new / 2) + 1);
	return two + two_new + odious_new;
}
int main()
{
	freopen("odious_edited_in.txt", "r", stdin);
	freopen("odious_edited_out.txt", "w", stdout);
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
