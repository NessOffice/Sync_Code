#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5;
struct Gate{int type, val;}gates[maxn];
int n, m, ans;
int simulate(int in)
{
    int out = in;
    for(int i = 0;i < n;i++)
    {
        if(gates[i].type == 'A') out &= gates[i].val;
        if(gates[i].type == 'O') out |= gates[i].val;
        if(gates[i].type == 'X') out ^= gates[i].val;
    }
    return out;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++)
    {
        char type_str[5];
        scanf("%s%d", type_str, &gates[i].val);
        gates[i].type = type_str[0];
    }
    int bit = 1;
    while((bit << 1) <= m) bit <<= 1;
    while(bit)
    {
        if(m < bit){bit >>= 1;continue;}
        int val1, val2;
        val1 = simulate(1*bit);
        val2 = simulate(0*bit);
        if(val1 > val2)
            m -= bit, ans += bit;
        bit >>= 1;
    }
    printf("%d", simulate(ans));
    return 0;
}
