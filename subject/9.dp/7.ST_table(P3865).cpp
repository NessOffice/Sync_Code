#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5; // 2**18 > maxn
int table[maxn][18];
int query(int l, int r)
{
	int len = r - l + 1, expo = 0; // expo for the exponential of 2
	while((1 << expo) < len) expo++; // we will get 2^expo >= len
	if((1 << expo) == len) return table[l][expo];
	else return max(table[l][expo-1], query(l + (1<<(expo-1)), r));
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d", &table[i][0]);
	for(int i = 1, len = 2;len <= n;i++, (len <<= 1))
		for(int j = 1;j + len - 1 <= n;j++)
			table[j][i] = max(table[j][i-1], table[j + len/2][i-1]);
	while(m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
	return 0;
}
