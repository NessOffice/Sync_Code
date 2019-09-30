#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long LL;
char b_str[20000005];
LL qmul(LL a, LL b, LL p)
{
    LL ans = 0;
    while(b)
    {
        if(b & 1LL)
            ans = (ans + a) % p;
        b >>= 1LL;
        a = (a + a) % p;
    }
    return ans;
}
int main()
{
    LL a, m, m_copy, phi_m, b = 0;
    scanf("%lld%lld", &a, &m);
    phi_m = m_copy = m;
    for(LL i = 2;i*i <= m_copy;i++)
    {
        if(m_copy % i == 0)
            phi_m = phi_m - phi_m / i;
        while(m_copy % i == 0)
            m_copy /= i;
    }
    if(m_copy != 1) // if prime
        phi_m = phi_m - phi_m / m_copy;
    bool flag = false;
    scanf("%s", b_str);
    for(int i = 0, len = strlen(b_str);i < len;i++)
    {
        b = b * 10 + b_str[i] - '0';
        if(b > phi_m)
        {
            b %= phi_m;
            flag = true;
        }
    }
    if(flag)
        b += phi_m;

    LL ans = 1;
    while(b)
    {
        if(b & 1LL)
            ans = qmul(ans, a, m);
        b >>= 1LL;
        a = qmul(a, a, m);
    }
    printf("%lld", ans);
    return 0;
}
