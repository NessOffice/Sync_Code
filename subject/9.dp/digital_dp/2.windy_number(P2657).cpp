#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register
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
			if((!j && k) || valid(j, k))
				dp[i][j] += dp[i-1][k];
	dp[1][0] = 0;
}
LL calc(LL bound)
{
	LL ans = 0, len = 0, digit[20];
	ans = (bound == 0 ? 1 : 0);
	do{
		digit[++len] = bound % 10;
		bound /= 10;
	}while(bound);
	for(LL i = 0;i < digit[len];i++)
		ans += dp[len][i];
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
