#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int solve(int *A, int l, int r)
{
	if(r-l == 1) return A[l];
	int m = l + (r-l)/2;
	int L, R, tempL, tempR, maxs;
	L = R = tempL = tempR = 0;
	maxs = max(solve(A, l, m), solve(A, m, r));
	for(int i = m-1;i >= l;i--)
		tempL += A[i],
		L = max(L, tempL);
	for(int i = m;i < r;i++)
		tempR += A[i],
		R = max(R, tempR);
	return max(maxs, L+R);
}
int main()
{
	int n, data[maxn];
	while(scanf("%d", &n) == 1)
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &data[i]);
		printf("%d\n", solve(data, 0, n));
	}
	return 0;
}
