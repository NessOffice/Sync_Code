#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5+5;
struct Line{pair<LL, LL> k, b;}lines[maxn];
map<pair<LL, LL>, LL> class_of_parallel; // k is same
map<pair<pair<LL, LL>, pair<LL, LL> >, LL> class_of_eq; // k is same and b is same
LL euclid(LL a, LL b)
{
	if(a < b) return euclid(b, a);
	return b == 0 ? a : euclid(b, a % b);
}
LL ABS(LL num){return num < 0 ? -num : num;}
pair<LL, LL> get_fraction(LL son, LL mom)
{
	LL d = euclid(ABS(son), ABS(mom));
	son /= d, mom /= d;
	if(mom < 0) son *= -1LL, mom *= -1LL;
	return make_pair(son, mom);
}
pair<LL, LL> calc_b(pair<LL, LL> k, pair<LL, LL> point)
{
	if(k.second == 0) return make_pair(point.first, 1);
	return get_fraction(k.second*point.second-k.first*point.first, k.second);
}
int main()
{
	LL T;
	scanf("%lld", &T);
	while(T--)
	{
		class_of_eq.clear();
		class_of_parallel.clear();
		LL n, ans = 0;
		scanf("%lld", &n);
		for(LL i = 0;i < n;i++)
		{
			LL x1, y1, x2, y2;
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			lines[i].k = get_fraction(y2-y1, x2-x1);
			lines[i].b = calc_b(lines[i].k, make_pair(x1, y1));
			class_of_parallel[lines[i].k]++;
			class_of_eq[make_pair(lines[i].k, lines[i].b)]++;
		}
		ans = 1LL*n*(n-1)/2;
		for(map<pair<LL, LL>, LL>::iterator iter = class_of_parallel.begin();iter != class_of_parallel.end();iter++)
			ans -= 1LL * iter->second * (iter->second - 1) / 2;
		for(map<pair<pair<LL, LL>, pair<LL, LL> >, LL>::iterator iter = class_of_eq.begin();iter != class_of_eq.end();iter++)
			ans += 1LL * iter->second * (iter->second - 1) / 2;
		printf("%lld\n", ans);
		// for(LL i = 0;i < n;i++)
		// {
		// 	LL num_of_eq = class_of_eq[make_pair(lines[i].k, lines[i].b)];
		// 	LL num_of_parallel = class_of_parallel[lines[i].k];
		// 	ans += (n-1 - num_of_parallel + num_of_eq);
		// }
		// printf("%lld\n", ans / 2);
	}
	return 0;
}
/*
4
2
0 0 0 1
1 0 1 1
2
0 0 1 0
0 1 1 1
2
0 0 1 1
0 0 1 1
2
0 0 1 1
0 1 1 0
*/