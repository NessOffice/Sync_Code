#include <cstdio>
const int MOD = 19260817;
inline int rd()
{
    char ch;
    int x = 0;
    int flag = 1;
    ch = getchar();
    while(ch > '9' || ch < '0')
    {
        if(ch == '-') flag = -1; // in this problem, this line won't be executed
        ch = getchar();
    }
    while(ch <= '9' && ch >= '0')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        x %= MOD; // this line is especially for this problem
        ch = getchar();
    }
    return flag * x;
}
int x, y;
void exgcd(int a, int b)
{
    if(b == 0){x = 1, y = 0;return;}
    exgcd(b, a % b);
    int temp = y;
    y = x - a / b * y;
    x = temp;
}
int main()
{
    int a = rd(), b = rd();
    exgcd(b, MOD);
    x = ((x % MOD) + MOD) % MOD;
    x = 1LL * x * a % MOD;
    if((1LL * b * x - a) % MOD == 0)
        printf("%d", x);
    else
        printf("Angry!");
    return 0;
}
