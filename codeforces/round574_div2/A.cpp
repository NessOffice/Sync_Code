#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e3 + 5;
int bucket[maxn];
int main()
{
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d", &temp);
        if(bucket[temp] & 1)
            ans++;
        bucket[temp]++;
    }
    ans += ((n+1)/2);
    printf("%d", ans);
    return 0;
}
