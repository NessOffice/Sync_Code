#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register
using namespace std;
typedef long long LL;
const LL maxn = 105;
const LL MOD = 9999973;
LL f[2][maxn][maxn]; // i-th row, j rows with 1 cannon, k rows with 2 cannons
inline LL C(LL x){return (x*(x-1)/2)%MOD;} // C(n, 2)
int main()
{
	LL n, m, ans = 0;
	scanf("%lld%lld", &n, &m);
	f[1][0][0] = 1;
	f[1][1][0] = m;
	f[1][2][0] = C(m);
	for(RE LL i_ = 2;i_ <= n;i_++)
	for(RE LL j = 0;j <= m;j++)
	for(RE LL k = 0;k <= m-j;k++)
	{
		LL i = i_ & 1;
		LL& res = f[i][j][k];
		res = f[i^1][j][k]; // put 0 cannons in i-th row

		if(k >= 1) res += (f[i^1][j+1][k-1]*(j+1));
		if(j >= 1) res += (f[i^1][j-1][k]*(m-j-k+1)); // put 1 cannon in i-th row

		if(k >= 2) res += (f[i^1][j+2][k-2]*C(j+2));
		if(j >= 2) res += (f[i^1][j-2][k]*C(m-j-k+2));
		if(k >= 1) res += (f[i^1][j][k-1]*j*(m-j-k+1)); // put 2 cannons in i-th row
		res %= MOD;
	}
	for(RE LL j = 0;j <= m;j++)
	for(RE LL k = 0;k <= m;k++)
		ans = (ans + f[n&1][j][k]) % MOD;
	printf("%lld", ans);
	return 0;
}
