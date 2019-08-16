#include <cstdio>
int n, eTwo = 0, ans = 1;
int f(int k)
{
    while(k%2 == 0)
        k /= 2,
        eTwo++;
    while(k%5 == 0)
        k /= 5,
        eTwo--;
    return k;
}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 2;i <= n;i++) ans = ans*f(i) % 10;
    for(int i = 1;i <= eTwo;i++) ans = ans*2 % 10;
    printf("%d\n", ans);
	return 0;
}
