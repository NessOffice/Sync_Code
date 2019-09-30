#include <cstdio>
#include <cstring>
const int maxn = 1e4+5;
int ans, n, b[maxn], a[maxn], delta[maxn];
bool flag = true;
void calc(int i)
{
	if(i < 3 || i > n) return;
	a[i] = a[i-3] + delta[i];
}
bool judge_a(int i){return (i > n || a[i] == 0 || a[i] == 1);}
bool judge_b(int i){return (i == 0 || i > n || (a[i-1] + a[i] + a[i+1] == b[i]));}
int main()
{
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &b[i]);
	for(int i = 1;i < n;i++)
		delta[i+2] = b[i+1] - b[i]; // a[n+2] - a[n-1] = b[n+1] - b[n]
	for(int i = 3;i <= n && flag;i += 3)
	{
		calc(i);
		flag = judge_a(i);
	}
	if(flag)
	for(int a1 = 0;a1 <= 1;a1++)
	{
		flag = true;
		a[1] = a1, a[2] = b[1]-a1;
		for(int i = 1;i <= n+3 && flag;i += 3)
		{
			calc(i);
			calc(i+1);
			flag = (judge_a(i) && judge_a(i+1) && judge_b(i-1) && judge_b(i) && judge_b(i+1));
		}
		if(flag) ans++;
	}
	printf("%d", ans);
	return 0;
}
