#include <cstdio>
#include <cmath>
typedef long long LL;
int main()
{
    LL kase = 1, n, ans, cnt, top;
    while(scanf("%lld", &n) && n)
    {
    	ans = cnt = 0;
	    top = sqrt(n) + 1;
	    for(LL i = 2;i <= top && n > 1;i++)
	    {
	        if(n % i) continue;
	        LL temp = 1;
	        while(n % i == 0)
	        {
	            temp *= i;
	            n /= i;
	        }
			cnt++;
	        ans += temp;
	    }
	    if(n > 1) ans += n, cnt++;
	    if(cnt < 2) ans += 2-cnt;
	    printf("Case %lld: %lld\n", kase++, ans);
	}
    return 0;
}
