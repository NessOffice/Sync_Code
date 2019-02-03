#include <cstdio>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n;
        scanf("%lld", &n);
        n--;
		long long cnt = 0;
		while(n)
		{
			if(n & 1) cnt++;
			n /= 2;
		}
		n = (1 << cnt);
		// long long k = __builtin_popcount(n); //得出二进制 n 中 1 的个数
		printf("%lld\n", n);
    }
    return 0;
}

/*
#include <cstdio>
int ans[1000] = {0, 1}, data[1000] = {1};
int main()
{
	for(int kase = 2;kase < 990;kase++)
	{
		ans[kase] = ans[kase-1] + 1, data[kase-1] = 1;
		for(int i = kase - 2;i > 0;i--)
		{
			int origin = data[i];
			data[i] = origin ^ data[i-1];
			if(data[i] > origin) ans[kase]++;
			else if(data[i] < origin) ans[kase]--;
		}
		printf("kase %d:%d\n", kase, ans[kase]);
	}
	return 0;
}
*/