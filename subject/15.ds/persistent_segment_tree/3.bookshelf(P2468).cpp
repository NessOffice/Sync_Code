#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, m, q;
const int maxn = 205;
const int maxp = 1000;
int rd(){int x;scanf("%d", &x);return x;}
namespace HJTTree
{
	const int maxsize = 1.1e7+5; // 5e5*20
	
	int cnt, sum[maxsize], sz[maxsize], tree[maxsize], ltree[maxsize], rtree[maxsize];
	int update(int id_pre, int l, int r, int x)
	{
		int id_now = ++cnt;
		ltree[id_now] = ltree[id_pre];
		rtree[id_now] = rtree[id_pre];
		sum[id_now] = sum[id_pre] + x;
		sz[id_now] = sz[id_pre] + 1;
		if(l == r) return id_now;
		int mid = l + r >> 1;
		if(x <= mid)
			ltree[id_now] = update(ltree[id_pre], l, mid, x);
		else
			rtree[id_now] = update(rtree[id_pre], mid+1, r, x);
		return id_now;
	}

	int query(int id_pre, int id_now, int l, int r, int k)
	{
		if(l == r) return (k + l - 1) / l;
		int mid = l + r >> 1;
		int sum_of_rsons = sum[rtree[id_now]] - sum[rtree[id_pre]];
		if(sum_of_rsons < k)
			return query(ltree[id_pre], ltree[id_now], l, mid, k - sum_of_rsons) + (sz[rtree[id_now]] - sz[rtree[id_pre]]);
		else
			return query(rtree[id_pre], rtree[id_now], mid+1, r, k);
	}

	void solve()
	{
		for(int i = 1;i <= m;i++)
			tree[i] = update(tree[i-1], 1, maxp, rd());

		while(q--)
		{
			int r1, c1, r2, c2, k;
			scanf("%d%d%d%d%d", &r1, &c1, &r2, &c2, &k);
			if(sum[tree[c2]] - sum[tree[c1-1]] >= k)
				printf("%d\n", query(tree[c1-1], tree[c2], 1, maxp, k));
			else
				printf("Poor QLW\n");
		}
	}
}
int a[maxn][maxn], sum2[maxn][maxn][maxp+1], sz2[maxn][maxn][maxp+1];
int calc_sum(int r1, int c1, int r2, int c2, int k){return sum2[r2][c2][k] - sum2[r1-1][c2][k] - sum2[r2][c1-1][k] + sum2[r1-1][c1-1][k];}
int calc_sz(int r1, int c1, int r2, int c2, int k){return sz2[r2][c2][k] - sz2[r1-1][c2][k] - sz2[r2][c1-1][k] + sz2[r1-1][c1-1][k];}
void solve()
{
	int maxv = 0;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= m;j++)
		scanf("%d", &a[i][j]),
		maxv = max(maxv, a[i][j]);

	for(int k = 0;k <= maxv;k++)
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= m;j++)
	{
		sum2[i][j][k] = sum2[i-1][j][k] + sum2[i][j-1][k] - sum2[i-1][j-1][k];
		sz2[i][j][k] = sz2[i-1][j][k] + sz2[i][j-1][k] - sz2[i-1][j-1][k];
		if(a[i][j] >= k) sum2[i][j][k] += a[i][j], sz2[i][j][k]++;
	}

	while(q--)
	{
		int r1, c1, r2, c2, k;
		scanf("%d%d%d%d%d", &r1, &c1, &r2, &c2, &k);
		if(calc_sum(r1, c1, r2, c2, 0) < k){printf("Poor QLW\n");continue;}
		int l = 0, r = maxv;
		while(l < r)
		{
			int mid = l + r + 1 >> 1;
			if(calc_sum(r1, c1, r2, c2, mid) >= k)
				l = mid;
			else
				r = mid-1;
		}
		int ans = calc_sz(r1, c1, r2, c2, l);
		ans -= (calc_sum(r1, c1, r2, c2, l)-k)/l;
		printf("%d\n", ans);
	}
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
	if(n == 1)
		HJTTree::solve();
	else
		solve();
    return 0;
}
