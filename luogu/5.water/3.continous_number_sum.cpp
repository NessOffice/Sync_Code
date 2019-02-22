#include <cstdio>
#include <cmath>
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
	int n;
    scanf("%d", &n);
    n *= 2;
    int begin = int(sqrt(n));
	for(int i = begin;i > 1;i--)
    {
        if(n % i) continue;
        int b = n / i;
        if(b <= i) continue;
        if((b-i+1)&1) continue;
        printf("%d %d\n", (b-i+1)/2, (b+i-1)/2);
    }
	return 0;
}
