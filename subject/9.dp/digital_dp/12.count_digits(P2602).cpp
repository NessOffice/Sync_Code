#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register
using namespace std;
typedef long long LL;
LL cnt[10];
void calc(LL num, LL flag, LL zeros)
{
	LL expo_10 = 0, base_10 = 1;
	if(num < 10)
	{
		while(num >= 0)
		{
			cnt[0] += flag*zeros;
			cnt[num] += flag;
			num--;
		}
		return;
	}

	while(base_10*10LL <= num)
		base_10 *= 10LL, expo_10++;

	LL remain = num % base_10; // num = 21234 => remain = 1234
	LL digit_top = num / base_10; // num = 21234 => digit_top = 2
	cnt[digit_top] += flag * (remain+1);
	cnt[0] += flag * zeros * (remain+1);
	if(remain && ) calc(remain, flag, zeros+1);
	num -= remain;
	num--; // num = 19999
	while(num >= base_10-1)
	{
		if(num >= base_10) cnt[num / base_10] += flag * (base_10-1);
		LL zeros_new = zeros;
		if(num >= base_10) zeros_new++;
		calc(base_10-1, flag, zeros_new);
		num -= base_10;
	}
}
int main()
{
	LL a, b;
	scanf("%lld%lld", &a, &b);
	calc(b, 1, 0);
	calc(a-1, -1, 0);
	for(LL i = 0;i < 10;i++)
		printf("%lld ", cnt[i]);
	return 0;
}
