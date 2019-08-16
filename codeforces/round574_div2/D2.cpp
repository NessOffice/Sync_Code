#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const LL MOD = 998244353;
struct Node{LL num; LL ws;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.ws < rhs.ws;}
LL digit[20], len, wssz[20];
LL fun(LL num)
{
    len = 0;
    while(num)
    {
        digit[++len] = num % 10;
        num /= 10;
    }
    LL ans = 0;
    while(len > 0)
    {
        ans *= 100LL;
        ans += (11*digit[len--]);
        ans %= MOD;
    }
    return ans;
}
LL get_ws(LL num)
{
    len = 0;
    do{
        len++;
        num /= 10;
    }while(num);
    return len;
}
LL houmian(LL num, LL w)
{
    len = 0;
    while(w)
    {
        digit[++len] = num % 10;
        num /= 10;
        w--;
    }
    LL ans = 0;
    while(len > 0)
    {
        ans *= 10LL;
        ans += digit[len--];
        ans %= MOD;
    }
    return ans;
}
LL qianmian(LL num, LL w)
{
    while(w)
    {
        num /= 10;
        w--;
    }
    return num;
}
int main()
{
    LL n, res = 0;
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++)
    {
        LL temp;
        scanf("%lld", &temp);
        nodes[i].num = temp;
        nodes[i].ws = get_ws(temp);
    }
    sort(nodes, nodes+n, cmp);
    LL ws_now = 1;
    for(LL i = 0;i < n;i++)
    {
        ws_now = nodes[i].ws;
        wssz[ws_now]++;
        for(LL w = 1;w <= ws_now;w++)
        {
            if(wssz[w] == 0) continue;
            LL part1 = houmian(nodes[i].num, w);
            LL part2 = qianmian(nodes[i].num, w);
            LL temp2 = wssz[w];
            // if(w < ws_now) temp2++;
            res = (res + temp2*fun(part1)) % MOD;
            for(LL w2 = 0;w2 < w;w2++)
                part2 = (part2 * 100LL) % MOD;
            res = (res + wssz[w]*2*part2) % MOD;
        }
        res = (res + (n-i-1)*fun(nodes[i].num)) % MOD;
    }
    printf("%lld", res);
    return 0;
}
