#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 3e3+5;
LL n, m, sum[maxn], dp[maxn][maxn];
LL head, tail, q[maxn];
LL calc_sum(LL j, LL k){return sum[j] - sum[k];} // j > k
void calc_dp(LL p, LL i, LL j){dp[i][p] = dp[j][p-1] + calc_sum(i, j)*calc_sum(i, j);} // j < i
LL calc_f(LL p, LL i){return dp[i][p] + sum[i]*sum[i];}
LL calc_son(LL p, LL j, LL k){return calc_f(p, j) - calc_f(p, k);} // j > k && sum is mom
int main()
{
	scanf("%lld%lld", &n, &m);
	sum[0] = dp[0][0] = 0;
	for(LL i = 1;i <= n;i++)
		scanf("%lld", sum + i);
	for(LL i = 1;i <= n;i++)
		sum[i] += sum[i-1],
		dp[i][1] = sum[i]*sum[i];
	for(LL p = 2;p <= m;p++)
	{
		head = tail = 0;
		q[tail++] = 0;
		for(LL i = 1;i <= n;i++)
		{
			while(head+1 < tail && calc_son(p-1, q[head+1], q[head]) <= 2*sum[i]*calc_sum(q[head+1], q[head])) head++;
			calc_dp(p, i, q[head]);
			while(head+1 < tail && calc_son(p-1, i, q[tail-1])*calc_sum(q[tail-1], q[tail-2]) <= calc_son(p-1, q[tail-1], q[tail-2])*calc_sum(i, q[tail-1])) tail--;
			q[tail++] = i;
		}
	}
	printf("%lld\n", m*dp[n][m]-sum[n]*sum[n]);
	return 0;
}
