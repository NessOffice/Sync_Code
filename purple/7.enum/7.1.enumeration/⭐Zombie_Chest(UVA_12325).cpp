#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int THRESHOLD = (1<<16);
int main()
{
	int T, s1, s2, n, v1, v2;
	scanf("%d", &T);
	for(int kase = 1;kase <= T;kase++)
	{
		scanf("%d%d%d%d%d", &n, &s1, &v1, &s2, &v2);
		if(s1 > s2)
		{
			swap(s1, s2);
			swap(v1, v2);
		}
		LL ans = 0;
		if(n / s2 > THRESHOLD){
			if(s2*v1 > s1*v2){
				for(LL i = 0;i < s1;i++)
					ans = max(ans, i*v2+(n-i*s2)/s1*v1);
			}else{
				for(LL i = 0;i < s2;i++)
					ans = max(ans, i*v1+(n-i*s1)/s2*v2);
			}
		}else{
			for(LL i = 0;i*s2 <= n;i++)
				ans = max(ans, i*v2+(n-i*s2)/s1*v1);
		}
		printf("Case #%d: %lld\n", kase, ans);
	}
	return 0;
}
