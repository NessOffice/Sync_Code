#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL maxn = 1e5 + 5;
char digits[maxn];
LL tong1[12], tong2[12];
int main()
{
	// freopen("end.in", "r", stdin);
	// freopen("end.out", "w", stdout);
	scanf("%s", digits);
	for(LL i = strlen(digits)-1;i >= 0;i--)
	{
		LL ch = digits[i];
		if('0' <= ch && ch <= '9')
			tong1[ch-'0']++;
		if(ch == '?')
			tong1[10]++;
	}
	LL ans = 0;
	for(int i = 1;i <= 5;i++) // how 10 is gained
	{
		LL ans_temp = 1;
		tong1[i]--, tong1[10-i]--;
		if(tong1[i] < 0) tong1[i]++, tong1[10]--;
		if(tong1[10-i] < 0) tong1[10-i]++, tong1[10]--;
		if(tong1[10] < 0){ans_temp = 0;continue;}
		
	}
	// for(LL i = 9;i > 0;i--)
	// {
	// 	LL delta = min(tong1[i], tong1[9-i])-1;
	// 	if(delta > 0)
	// 		tong1[i] -= delta,
	// 		tong1[9-i] -= delta;
	// }
	// tong1[0] &= 1;
	// LL sum = 0;
	// for(LL i = 0;i <= 9;i++)
	// 	sum += tong1[i];
	return 0;
}
/*
2?4?
29?2?3
?820
*/