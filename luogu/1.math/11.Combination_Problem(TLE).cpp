#include <cstdio>
#include <algorithm>
using namespace std;
int prime[10], expo[10], len = 0;
bool judge(int i, int j)
{
    for(int p = len-1;p >= 0;p--)
    {
        int k = prime[p], k1 = prime[p], d = 0;
        while(i / k1)
        {
            d += i/k1;
            d -= j/k1;
            d -= (i-j)/k1;
            k1 *= k;
        }
        if(d <= expo[p]-1) return false;
    }
    return true;
}
//failed 2 points
int main()
{
    // freopen("in.txt", "r", stdin);
    int t, k, n, m, ans;
    scanf("%d%d", &t, &k);
    for(int i = 2;i <= k;i++)
        if(k % i == 0)
        {
            prime[len] = i;
            expo[len++] = 0;
            while(k % i == 0){k /= i;expo[len-1]++;}
        }
    while(t--)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n;i++)
        {
            int maxj = min(i, m);
            for(int j = 1;j <= maxj;j++)
                if(judge(i, j)) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
