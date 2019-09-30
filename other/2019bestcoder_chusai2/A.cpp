#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 5;
int ans[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, n0, sum = 0;
        scanf("%d", &n);
        n0 = n;
        while(n0)
        {
            sum += n0 % 10;
            n0 /= 10;
        }
        int cnt = 0;
        for(int i = 1;i <= sum;i++)
        {
            if(sum % i) continue;
            if(n % i) continue;
            ans[cnt++] = i;
        }
        printf("%d\n", cnt);
        for(int i = 0;i < cnt;i++)
        {
            if(i) putchar(' ');
            printf("%d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
