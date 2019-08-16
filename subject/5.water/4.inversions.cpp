#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e5 + 7;
LL n, data[maxn], temp[maxn], ans = 0;
void solve(LL *A, LL l, LL r, LL *T)
{
	if(r-l <= 1) return;
	LL m = (l+r)/2;
	solve(A, l, m, T);
	solve(A, m, r, T);
	LL p = l, q = m, i = l;
	while(p < m || q < r)
	{
		if(q >= r || (p < m && A[p] <= A[q])) T[i++] = A[p++];//tm A[p] == A[q]
		else{ans += (m-p);T[i++] = A[q++];}
	}
	for(i = l;i < r;i++) A[i] = T[i];
}
int main()
{
	// freopen("in.txt", "r", stdin);
	scanf("%lld", &n);
	for(LL i = 0;i < n;i++)
		scanf("%lld", &data[i]);
	solve(data, 0, n, temp);
	printf("%lld\n", ans);
	return 0;
}
