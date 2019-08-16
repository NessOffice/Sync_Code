#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 1e9 + 7;
const int maxn = (1 << 9);
int main()
{
    int n, m, num_by_bit[maxn], index_by_bit[maxn], price_by_bit[maxn];
    memset(num_by_bit, 0, sizeof(num_by_bit));
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        int fi, ai = 0;
        scanf("%d", &fi);
        while(fi--)
        {
            int bi;
            scanf("%d", &bi);
            ai += (1 << (bi - 1));
        }
        for(int bit2 = ai;bit2 < maxn;bit2++)
            if((bit2 & ai) == ai)
                num_by_bit[bit2]++;
    }
    
    for(int bit = 0;bit < maxn;bit++)
        price_by_bit[bit] = INF;
    for(int i = 1;i <= m;i++)
    {
        int price, fi, ai = 0;
        scanf("%d", &price);
        scanf("%d", &fi);
        while(fi--)
        {
            int bi;
            scanf("%d", &bi);
            ai += (1 << (bi - 1));
        }
        if(price < price_by_bit[ai])
        {
            price_by_bit[ai] = price;
            index_by_bit[ai] = i;
        }
    }

    int max_num = 0, min_price = 0, pizza1 = -1, pizza2 = -1;
    for(int bit1 = 0;bit1 < maxn;bit1++)
    for(int bit2 = bit1+1;bit2 < maxn;bit2++)
        if(price_by_bit[bit1] < INF && price_by_bit[bit2] < INF)
        {
            if((num_by_bit[bit1 | bit2] > max_num)
            || (num_by_bit[bit1 | bit2] == max_num && price_by_bit[bit1] + price_by_bit[bit2] < min_price))
            {
                max_num = num_by_bit[bit1 | bit2];
                min_price = price_by_bit[bit1] + price_by_bit[bit2];
                pizza1 = bit1;
                pizza2 = bit2;
            }
        }
    if(max_num == 0)
    {
        int min_price1 = INF, min_price2 = INF;
        for(int bit = 0;bit < maxn;bit++)
        {
            if(price_by_bit[bit] < min_price2)
            {
                if(price_by_bit[bit] < min_price1){
                    min_price2 = min_price1;
                    min_price1 = price_by_bit[bit];
                    pizza2 = pizza1;
                    pizza1 = bit;
                }else{
                    min_price2 = price_by_bit[bit];
                    pizza2 = bit;
                }
            }
        }
    }
    if(pizza2 == -1 || pizza1 == -1)
        printf("1 2");
    else
        printf("%d %d", index_by_bit[pizza1], index_by_bit[pizza2]);
    return 0;
}
