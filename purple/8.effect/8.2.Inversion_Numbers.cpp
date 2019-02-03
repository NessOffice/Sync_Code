#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int ans;
void solve(int *A, int l, int r, int *T)
{
	if(r-l == 1) return;
	int m = l + (r-l)/2;
	solve(A, l, m, T);
	solve(A, m, r, T);
	int p = l, q = m, i = l;
	while(p < m || q < r)
	{
		if(q >= r || (p < m && A[p] < A[q]))T[i++] = A[p++];
		else{ans += (m-p);T[i++] = A[q++];}
	}
	for(i = l;i < r;i++) A[i] = T[i];
}
int main()
{
	int n, data[maxn], temp[maxn];
	while(ans = 0, scanf("%d", &n) == 1)
	{
		for(int i = 0;i < n;i++)
			scanf("%d", &data[i]);
		solve(data, 0, n, temp);
		printf("%d\n", ans);
	}
	return 0;
}
