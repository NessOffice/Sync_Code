#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long LL;
LL extend_euclid(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL r = extend_euclid(b, a%b, x, y);
    LL temp = y;
    y = x - (a/b)*y;
    x = temp;
    return r;
}
int main()
{
	// freopen("end.in", "r", stdin);
	// freopen("end.out", "w", stdout);
	LL T;
	scanf("%lld", &T);
	while(T--)
	{
		LL a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		LL x, y, d;
		d = __gcd(a, b);
		if(c % d || (c > a && c > b))
		{
			printf("-1\n");
			continue;
		}
		a /= d, b /= d, c /= d;
		if(a > b) swap(a, b);
		if(c == a || c == b)
		{
			printf("1\n");
			continue;
		}
		extend_euclid(a, b, x, y);
		x = x * c % b;
		if(x < 0) x += b;
		// x = min(x, b-x);
		LL ans, ans1 = 2*(x+x*a/b)-(c<a?2:0), ans2 = (b-x)*a/b*2+(b-x)*2;
		ans = min(ans1, ans2);
		printf("%lld\n", ans);
	}
	return 0;
}
/*
10
1000000007 998244353 100000

100
8 13 11
17 1 9
17 6 19
6 14 2
13 19 7
7 12 13
12 14 17
14 9 19
12 2 9
4 12 10
6 10 2
14 7 6
12 7 20
20 6 16
12 9 12
10 3 17
13 17 15
12 19 9
14 17 12
17 6 6
8 4 4
18 16 19
8 12 15
11 15 10
20 18 16
8 19 13
20 17 11
1 7 20
8 1 11
17 20 5
1 20 1
12 1 9
20 16 19
14 4 9
1 15 19
1 10 5
9 14 10
4 5 20
13 4 2
14 19 5
11 9 2
1 11 11
12 20 15
10 15 17
5 2 16
12 3 5
19 12 11
18 3 11
12 2 5
10 8 9
19 8 7
18 11 15
12 8 20
8 15 6
8 11 7
9 1 14
16 2 10
8 16 10
12 6 2
19 4 13
19 6 17
13 5 12
7 14 17
15 7 20
11 17 1
15 8 12
6 4 6
20 3 12
3 10 18
19 13 18
10 2 3
13 8 16
13 15 14
13 7 10
11 4 16
5 17 10
14 18 6
18 2 17
16 8 16
5 17 14
3 6 14
5 10 13
6 12 10
6 6 17
5 20 14
10 11 5
6 17 16
1 14 18
14 3 18
20 1 10
14 6 10
7 9 4
1 14 7
8 8 14
2 13 20
1 19 1
14 19 19
17 9 17
17 3 18
17 7 6

1000
1 1000 499
1 1000 500
1 1000 501
1 1001 500
1 1001 501
2 3 1
2 3 2
2 3 3
2 3 4
2 5 1
2 5 3
2 5 4
2 9 7
3 10 8
5 3 7
*/