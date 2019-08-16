#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1.5e5+5;
const int sqrtmaxn = 400;
int ans[sqrtmaxn][sqrtmaxn], value[maxn];
int main()
{
    int n, m, border;
    scanf("%d%d", &n, &m);
    border = pow(n, 0.5);
    for(int i = 1;i <= n;i++)
    {
    	scanf("%d", value + i);
        for(int p = 1;p <= border;p++)
            ans[p][i%p] += value[i];
    }
    while(m--)
    {
        char cmd_str[2];
        int x, y;
        scanf("%s%d%d", cmd_str, &x, &y);
        if(cmd_str[0] == 'A')
        {
            int res = 0, p = x, k = y;
            if(p <= border) res = ans[p][k];
            else for(int i = k;i <= n;i += p) res += value[i];
            printf("%d\n", res);
        }
        if(cmd_str[0] == 'C')
        {
            int val_new = y, k = x;
            for(int p = 1;p <= border;p++)
                    ans[p][k%p] = ans[p][k%p] - value[k] + val_new;
            value[k] = val_new;
        }
    }
    return 0;
}

