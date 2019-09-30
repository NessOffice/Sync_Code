#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 5e5+5;
double sq[maxn];
LL n, a[maxn], ans[maxn], border[maxn], q[maxn];
double calc(LL i, LL j){return a[j] + sq[i-j];}
LL bound(LL x, LL y)
{
	LL l = y + 1, r = n;
	if(l == 0) l = 1;
	while(l < r)
	{
		LL mid = l + r >> 1;
		if(calc(mid, x) <= calc(mid, y))
			r = mid;
		else
			l = mid + 1;
	}
	if(calc(l, x) > calc(l, y))
		l = n + 1;
	return l;
}
void solve()
{
	for(LL i = 1, head = 1, tail = 0;i <= n;i++)
	{
		while(head < tail && border[head] <= i) head++;
		while(head < tail && border[tail-1] >= bound(q[tail], i)) tail--;
		border[tail] = bound(q[tail], i);
		q[++tail] = i;
		ans[i] = max(ans[i], (LL)(ceil(calc(i, q[head]))));
	}
}
void turn()
{
	for(LL i = 1;i <= n / 2;i++)
		swap(a[i], a[n+1-i]), swap(ans[i], ans[n+1-i]);
}		
int main()
{
	scanf("%lld", &n);
	for(LL i = 1;i <= n;i++)
		scanf("%lld", a + i), sq[i] = sqrt(i);
	solve();
	turn();
	solve();
	for(LL i = n;i >= 1;i--)
		printf("%lld\n", max(ans[i]-a[i], 0LL));
	return 0;
}
