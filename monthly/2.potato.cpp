#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll p[18];
void init()//p[i]即 10^p
{
	p[0] = 0;
	p[1] = 10;
	for (int i = 2;i <= 17;i++)
	{
		p[i] = p[i - 1] * 10;
	}
}
int go(int x)//计算 x 的位数
{
	int cnt = 0;
	while (x)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}
ll f(ll x)
{
	int cnt = go(x);
	if (cnt == 1)
		return  x - p[cnt - 1] - 1;
	ll sum_ = x - p[cnt - 1];
	for (int i = 1;i < cnt;i++)
	{
		ll sum = x / p[i];
		if (i == cnt - 1)
			sum_ += sum - p[cnt - i - 1];
		else
			sum_ += sum - p[cnt - i - 1] + 1;
	}
	return sum_;
}
 
ll ff(ll x, int m)
{
	int cnt = go(x);
	ll sum = x;
	ll sum_ = 0;
	for (int i = cnt;;i++)
	{
		sum = sum * 10;
		sum_ = sum - p[i];
		if(sum_ <= m)
			m -= sum_;
		else
			return p[i] + m - 1;
	}
}
int main()
{
	int T;
	cin >> T;
	init();
	while (T--) {
		ll k, m;
		scanf("%lld%lld", &k, &m);
		m = m - f(k) - 1;
		if (m < 0)
		{
			cout << 0 << endl;
			continue;
		}
		if (m == 0)
		{
			cout << k << endl;
			continue;
		}
		cout << ff(k, m) << endl;
 
	}
	return 0;
}