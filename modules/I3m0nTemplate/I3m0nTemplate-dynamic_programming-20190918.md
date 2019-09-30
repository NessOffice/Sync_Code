# dp-1.斜率优化

根据状态转移方程（通常是取min或max）得到的不等式的等价变换来维护凸包以在$O(n)$的复杂度内求出$dp[n]$。

例题：状态转移方程为$dp[i] = min \{ dp[j] + (sum[i] - sum[j])^2 + M \}$。

~~~cpp
const LL maxn = 5e5+5;
LL n, m, sum[maxn], dp[maxn];
LL head, tail, q[maxn];
LL calc_sum(LL j, LL k){return sum[j] - sum[k];} // j > k
void calc_dp(LL i, LL j){dp[i] = dp[j] + calc_sum(i, j)*calc_sum(i, j) + m;} // j < i
LL calc_f(LL i){return dp[i] + sum[i]*sum[i];}
LL calc_son(LL j, LL k){return calc_f(j) - calc_f(k);} // j > k && sum is mom
int main()
{
	while(~scanf("%lld%lld", &n, &m))
	{
		sum[0] = dp[0] = 0;
		for(LL i = 1;i <= n;i++)
			scanf("%lld", sum + i);
		for(LL i = 1;i <= n;i++)
			sum[i] += sum[i-1];
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
	}
	return 0;
}
~~~

# dp-2.四边形不等式优化

四边形不等式用于处理区间类动态规划问题：$dp(l, r) = min\{dp(l, k) + dp(k+1, r)\} + w(l, r)$。

四边形不等式：$l_1 \leq l_2 \leq r_1 \leq r_2 \Rightarrow w(l_1, r_1) + w(l_2, r_2) \leq w(l_2, r_1) + w(l_1, r_2)$。

结论：若w满足四边形不等式，则状态dp亦满足四边形不等式，此时决策点m满足$m(l, r-1) \leq m(l, r) \leq m(l+1, r)$。

故可在计算dp时更新决策点m，使得复杂度由$O(n^3)$降至$O(n^2)$。

~~~cpp
for (int len = 2; len <= n; ++len)  // 枚举区间长度
  for (int l = 1, r = len; r <= n; ++l, ++r) {
    // 枚举长度为len的所有区间
    f[l][r] = INF;
    for (int k = m[l][r - 1]; k <= m[l + 1][r]; ++k)
      if (f[l][r] > f[l][k] + f[k + 1][r] + w(l, r)) {
        f[l][r] = f[l][k] + f[k + 1][r] + w(l, r);  // 更新状态值
        m[l][r] = k;  // 更新（最小）最优决策点
      }
  }
~~~

# dp-3.单调队列优化

思路简单，略。





// ver1.0 updated by Ness, 20190918