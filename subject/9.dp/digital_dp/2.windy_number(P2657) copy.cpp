#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL dp[20][10];
bool valid(LL x, LL y){return abs(x-y) >= 2;}
void init()
{
	for(LL i = 0;i < 10;i++)
		dp[1][i] = 1;
	for(LL i = 2;i < 20;i++)
		for(LL j = 0;j < 10;j++)
		for(LL k = 0;k < 10;k++)
			if(valid(j, k))
				dp[i][j] += dp[i-1][k];
}
LL calc(LL bound)
{
	if(bound <= 0) return 0;
	LL ans = 0, len = 0, digit[20];
	do{
		digit[++len] = bound % 10;
		bound /= 10;
	}while(bound);
	for(LL i = 0;i < len;i++)
		for(LL j = 1;j < 10;j++)
			ans += dp[i][j];
	for(LL j = 1;j < digit[len];j++)
		ans += dp[len][j];
	for(LL i = len-1;i > 0;i--)
	{
		for(LL j = 0;j < digit[i];j++)
			if(valid(j, digit[i+1]))
				ans += dp[i][j];
		if(!valid(digit[i+1], digit[i]))
			break;
	}
	return ans;
}
int main()
{
	init();
	LL a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", calc(b+1) - calc(a));
	return 0;
}
