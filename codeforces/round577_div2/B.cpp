#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL num[maxn];
int main()
{
    LL n;
    scanf("%lld", &n);
    for(int i = 0;i < n;i++)
        scanf("%lld", &num[i]);
    sort(num, num + n);
    LL sum = 0;
    for(int i = 0;i < n-1;i++)
        sum += num[i];
    bool ok = true;
    if(sum < num[n-1]) ok = false;
    if((sum + num[n-1]) & 1) ok = false;
    printf("%s", ok ? "YES" : "NO");
    return 0;
}
