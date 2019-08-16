#include <cstdio>
#include <cstring>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
int n, m, a[maxn], b[maxn];
int rd(){int x;scanf("%d", &x);return x;}
bool judge(int num_of_dev) // dev for device, dep for depth, sk for sockets
{
	int ptr_of_plug = 0, num_of_sk_now = 1, num_of_sk_nxt = 0;
	int num_begin = num_of_dev, dep_begin = maxn-1;
	while(1)
	{
		if(num_begin - b[dep_begin] <= 0) break;
		else num_begin -= b[dep_begin--];
	}
	for(int dep = 0;num_of_dev;dep++)
	{
		if(num_of_dev <= num_of_sk_now){num_of_dev = 0;break;}
		if(dep == dep_begin){num_of_sk_now -= num_begin;num_of_dev -= num_begin;}
		if(dep > dep_begin)
		{
			if(num_of_sk_now < b[dep]) break;
			else num_of_sk_now -= b[dep], num_of_dev -= b[dep];
		}
		while(ptr_of_plug < n && num_of_sk_now)
		{
			num_of_sk_now--;
			num_of_sk_nxt += a[ptr_of_plug++];
		}
		num_of_sk_now += num_of_sk_nxt;
		num_of_sk_nxt = 0;
		if(num_of_sk_now == 0) break;
	}
	return num_of_dev == 0;
}
int main()
{
	n = rd();m = rd();
	for(int i = 0;i < n;i++) a[i] = rd();
	for(int i = 0;i < m;i++) b[rd()]++;
	sort(a, a+n, greater<int>());
	int l = 1, r = m;
	while(l < r)
	{
		int mid = l+r+1>>1;
		if(judge(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d", l);
	return 0;
}
