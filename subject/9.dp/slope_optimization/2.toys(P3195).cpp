#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e4+5;
LL n, m, L, sum[maxn], dp[maxn];
LL head, tail, q[maxn];
LL calc_sum(LL j, LL k){return sum[j] - sum[k];} // j > k
void calc_dp(LL i, LL j){dp[i] = dp[j] + (calc_sum(i, j)-L)*(calc_sum(i, j)-L);} // j < i
LL calc_f(LL i){return dp[i] + sum[i]*sum[i] + 2*L*sum[i];}
LL calc_son(LL j, LL k){return calc_f(j) - calc_f(k);} // j > k && sum is mom
int main()
{
	scanf("%lld%lld", &n, &L);
	L++;
	sum[0] = dp[0] = 0;
	for(LL i = 1;i <= n;i++)
		scanf("%lld", sum + i);
	for(LL i = 1;i <= n;i++)
		sum[i] += sum[i-1];
	for(LL i = 1;i <= n;i++)
		sum[i] += i;
	head = tail = 0; // caution!!!
	q[tail++] = 0;
	for(LL i = 1;i <= n;i++)
	{
		while(head+1 < tail && calc_son(q[head+1], q[head]) <= 2*sum[i]*calc_sum(q[head+1], q[head])) head++;
		calc_dp(i, q[head]);
		while(head+1 < tail && calc_son(i, q[tail-1])*calc_sum(q[tail-1], q[tail-2]) <= calc_son(q[tail-1], q[tail-2])*calc_sum(i, q[tail-1])) tail--;
		q[tail++] = i;
	}
	printf("%lld\n", dp[n]);
	return 0;
}
