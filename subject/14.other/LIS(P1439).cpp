#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int n, pos[maxn], data[maxn], dp[maxn];
int rd(){int a;scanf("%d", &a);return a;}
int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        pos[rd()] = i;
    for(int i = 1;i <= n;i++)
        data[i] = pos[rd()];
    // above: convert the "LCS" problem to the LIS problem

    int len = 0;
    dp[++len] = data[1]; // dp[i] for the least element in a subsequence whose length equals i
    for(int i = 2;i <= n;i++)
    {
        if(data[i] > dp[len])
            dp[++len] = data[i];
        else
        {
            int l = 1, r = len;
            while(l < r)
            {
                int mid = (l+r) / 2;
                if(data[i] > dp[mid])
                    l = mid+1;
                else
                    r = mid;
            }
            dp[l] = data[i];
        }
    }
    printf("%d", len);
    return 0;
}
