#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
const LL maxn = 1e6 + 5;
const LL base = 1e6 + 5;
const LL MOD_NUM[] = {1e9+7, 998244353};
LL jmp[maxn], nxt[maxn];
LL s1[maxn], s2[maxn];
LL n, m, num;
LL qpow(LL expo, LL MOD)
{
    LL ans = 1, b = base;
    while(expo)
    {
        if(expo & 1LL)
            ans = ans * b % MOD;
        expo >>= 1LL;
        b = b * b % MOD;
    }
    return ans;
}
bool is_same(pair<LL, LL> hash_val1, pair<LL, LL> hash_val2){return hash_val1.first == hash_val2.first && hash_val1.second == hash_val2.second;}
int main()
{
    scanf("%lld%lld", &n, &m);
    map<LL, LL> last;
    for(LL i = 0;i < n;i++)
        scanf("%lld", s1 + i);
    for(LL i = 0;i < m;i++)
        scanf("%lld", s2 + i);
    for(LL i = 0;i < m;i++)
    {
        LL num = s2[i];
        if(last.count(num))
            nxt[last[num]] = i,
            jmp[i] = i - last[num];
        last[num] = i;
    }
    LL hash_val1 = 0, hash_val2 = 0;
    for(LL i = 0;i < m;i++)
    {
        hash_val1 = (hash_val1 * base + jmp[i]) % MOD_NUM[0];
        hash_val2 = (hash_val2 * base + jmp[i]) % MOD_NUM[1];
    }
    pair<LL, LL> pattern = make_pair(hash_val1, hash_val2);

    last.clear();
    memset(jmp, 0, sizeof(jmp));
    memset(nxt, 0, sizeof(nxt));
    for(LL i = 0;i < n;i++)
    {
        LL num = s1[i];
        if(last.count(num))
            nxt[last[num]] = i,
            jmp[i] = i - last[num];
        last[num] = i;
    }
    hash_val1 = hash_val2 = 0;
    for(LL i = 0;i < m;i++)
    {
        hash_val1 = (hash_val1 * base + jmp[i]) % MOD_NUM[0];
        hash_val2 = (hash_val2 * base + jmp[i]) % MOD_NUM[1];
    }
    pair<LL, LL> text;
    LL cnt = 0;
    for(LL i = m;i < n;i++)
    {
        text = make_pair(hash_val1, hash_val2);
        if(is_same(pattern, text)) cnt++;
        if(nxt[i-m])
        {
            if(nxt[i-m] < i)
            {
                hash_val1 = (hash_val1-(jmp[nxt[i-m]]*qpow(i-1-nxt[i-m], MOD_NUM[0])%MOD_NUM[0])+MOD_NUM[0])%MOD_NUM[0];
                hash_val2 = (hash_val2-(jmp[nxt[i-m]]*qpow(i-1-nxt[i-m], MOD_NUM[1])%MOD_NUM[1])+MOD_NUM[1])%MOD_NUM[1];
            }
            jmp[nxt[i-m]] = 0;
        }

        // jmp[head] = 0, so it's not necessary to minus this term
        hash_val1 = (hash_val1 * base + jmp[i]) % MOD_NUM[0];
        hash_val2 = (hash_val2 * base + jmp[i]) % MOD_NUM[1];
    }
    text = make_pair(hash_val1, hash_val2);
    if(is_same(pattern, text)) cnt++;
    printf("%lld\n", cnt);
    return 0;
}
