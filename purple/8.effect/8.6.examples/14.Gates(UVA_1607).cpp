#include <cstdio>
const int maxn = 200000 + 10;
int gas[maxn][2], T, n, m;
struct Gate{
	int in1, in2, out;
}gates[maxn];
int calc(int in)
{
	for(int i = 1;i <= m;i++)
	{
		int in1 = gates[i].in1;
		int in2 = gates[i].in2;
		int v1, v2;
		v1 = in1 < 0 ? (-in1 <= in) : gates[in1].out;
		v2 = in2 < 0 ? (-in2 <= in) : gates[in2].out;
		gates[i].out = !(v1 && v2);
	}
	return gates[m].out;
}
int solve(int vn)
{
	int L = 1, R = n;
	while(L < R)
	{
		int M = L + (R-L)/2;
		if(calc(M) == vn) R = M;
		else L = M + 1;
	}
	return L;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++)
			scanf("%d%d", &gates[i].in1, &gates[i].in2);
		int v0 = calc(0);
		int vn = calc(n);
		if(v0 == vn)
			for(int i = 1;i <= n;i++) putchar('0');
		else
		{
			int x = solve(vn);
			for(int i = 1;i < x;i++) putchar('1');
			putchar('x');
			for(int i = x+1;i <= n;i++) putchar('0');
		}
		putchar('\n');
	}
	return 0;
}