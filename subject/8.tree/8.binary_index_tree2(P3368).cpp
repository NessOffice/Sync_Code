#include <cstdio>
typedef long long LL;
const LL maxn = 5e5 + 5;
LL lowbit(LL num){return (num & -num);}
LL n, m, x, y, k, tree[maxn];
void change(LL begin, LL num)
{
	for(LL i = begin;i <= n;i += lowbit(i))
		tree[i] += num;
}
LL query(LL begin)
{
	LL ans = 0;
	for(LL i = begin;i > 0;i -= lowbit(i))
		ans += tree[i];
	return ans;
}
int main()
{
	scanf("%lld%lld", &n, &m);
	LL last = 0, now;
	for(LL i = 1;i <= n;i++)
	{
		scanf("%lld", &now);
		change(i, now-last);
		last = now;
	}
	while(m--)
	{
		LL cmd, num;
		scanf("%lld", &cmd);
		if(cmd == 1) scanf("%lld%lld%lld", &x, &y, &num);
		if(cmd == 2) scanf("%lld", &x);

		if(cmd == 1){change(x, num);change(y+1, -num);}
		if(cmd == 2) printf("%lld\n", query(x));
	}
    return 0;
}
