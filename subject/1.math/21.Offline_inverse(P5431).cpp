#include <cstdio>
#include <cstring>
#include <algorithm>
#define RE register int
using namespace std;
typedef long long LL;
const int maxn = 5e6+5;
inline int rd()
{
    char c;
    int x = 0;
    int flag = 1;
    c = getchar();
    while(c > '9' || c < '0')
    {
        if(c == '-') flag = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag * x;
}
int qpow(int base, int expo, int p)
{
    int ans = 1;
    while(expo)
    {
        if(expo & 1)
            ans = 1LL * ans * base % p;
        expo >>= 1;
        base = 1LL * base * base % p;
    }
    return ans;
}
int a[maxn], a_inv[maxn], pi[maxn], pi_inv[maxn];
int main()
{
    int n = rd(), p = rd(), k = rd();
    pi[0] = 1;
    for(RE i = 1;i <= n;i++)
    {
        a[i] = rd();
        pi[i] = 1LL * pi[i-1] * a[i] % p;
    }
    pi_inv[n] = qpow(pi[n], p-2, p);
    for(RE i = n-1;i >= 1;i--)
    {
        pi_inv[i] = 1LL * a[i+1] * pi_inv[i+1] % p;
        a_inv[i+1] = 1LL * pi[i] * pi_inv[i+1] % p;
    }
    a_inv[1] = pi_inv[1];
    int ans = 0;
    for(RE i = n;i >= 1;i--)
    {
        ans = 1LL * ans * k % p;
        ans = (1LL * ans + 1LL * a_inv[i] % p * k) % p;
    }
    printf("%d", ans);
    return 0;
}
