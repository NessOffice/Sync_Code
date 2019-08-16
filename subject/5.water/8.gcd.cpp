#include <cstdio>
int x, y, cnt;
int gcd(int a, int b){return a % b ? gcd(b, a%b) : b;}
void solve(int y, int x)
{
    if(y % x) return;
    if(y == x){cnt = 1;return;}
    y /= x;
	for(int i = 1;i*i < y;i++)
    {
        if(y % i) continue;
        if(gcd(y/i, i) == 1) cnt++;
    }
    cnt *= 2;
}
int main()
{
//	  freopen("in.txt", "r", stdin);
//	  freopen("out.txt", "w", stdout);
    cnt = 0;
    scanf("%d%d", &x, &y);
    solve(y, x);
    printf("%d\n", cnt);
	return 0;
}
