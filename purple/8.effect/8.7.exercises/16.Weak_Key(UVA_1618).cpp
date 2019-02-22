#include <cstdio>
#include <algorithm>
const int maxn = 5000 + 5;
int k, a[maxn], L[maxn][maxn], R[maxn][maxn];
//p < q < r < s, aim:Nq > Ns > Np > Nr(or <)
//L[r][q]:index(< q) of the minimum number > a[r]
bool solve(int flag)
{
	if(!flag) std::reverse(a+1, a+k+1);
	for(int r = 1;r < k;r++)
	{
		L[r][0] = R[r][k+1] = 0;
		for(int q = 1;q < r;q++)
		{
			if(a[q] > a[r] && (!L[r][q-1] || a[q] < a[L[r][q-1]]))
				L[r][q] = q;
			else L[r][q] = L[r][q-1];
		}
		for(int s = k;s > r;s--)
		{
			if(a[s] < a[r] && (!R[r][s+1] || a[s] > a[R[r][s+1]]))
				R[r][s] = s;
			else R[r][s] = R[r][s+1];
		}
	}
	for(int q = 1;q < k;q++)
	for(int r = q+1;r < k;r++)
	{
		if(a[r] >= a[q] || !L[r][q] || !R[q][r]) continue;
		int p = L[r][q], s = R[q][r];
		if(a[s] > a[p]) return true;
	}
	return flag ? solve(0) : false;
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &k);
		for(int i = 1;i <= k;i++)
			scanf("%d", a+i);
		printf("%s\n", solve(1) ? "YES" : "NO");
	}
	return 0;
}
