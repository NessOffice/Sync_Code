#include <cstdio>
typedef long long LL;
bool judge(LL a, LL b)
{
	if(a < b) return judge(b, a);
	if(a >= 2*b || a == b) return true;
	return !judge(b, a-b);
}
int main()
{
	//   freopen("in.txt", "r", stdin);
	//   freopen("out.txt", "w", stdout);
	LL T, m, n;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld%lld", &m, &n);
		printf("%s wins\n", judge(m, n) ? "Stan" : "Ollie");
	}
	return 0;
}
