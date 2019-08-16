#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	LL m, k = 0, base = 0, ans;
	char k_str[20];
	scanf("%s%lld", k_str, &m); // if k = 357
	m--; // in front of k, there're m-1 numbers
	for(LL i = 0, len = strlen(k_str);i < len;i++)
	{
		k = k*10 + (k_str[i]-'0');
		m -= (k - base); // delete the numbers in front of k with i-digits
		base = base*10 + 9; // base: 999
	}
	m++; // in the procedure above, we deleted 357, so compensate for it
	ans = (m >= 0 ? k : 0); // if m == 0, output k; if m < 0, output 0
	base++; // base: 1000
	k -= (base / 10); // k: 357->257, for convenience in calculation

	if(k == 0 && m > 0) ans = 0; // special judge! k = 0!

	if(m > 0 && k > 0) // calc ans only when m > 0
	while(m)
	{
		k *= 10;
		LL del = min(m, k); // 1000-3569
		m -= del; // delete the numbers in front of k in [base, 10*base)
		ans = base + del - 1;
		base *= 10;
	}
	printf("%lld", ans);
	return 0;
}
