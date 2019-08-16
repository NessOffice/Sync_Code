#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    int n, ans = -1, step = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", a + i);
    sort(a, a + n);
    if(n > 1 && a[1] == 0) ans = 0; // special judge 1
    for(int i = 0;i+2 < n;i++)
        if(a[i+1] == a[i+2] && a[i] + 1 == a[i+1]) ans = 0; // special judge 2
    int cnt = 0;
    for(int i = 0;i+1 < n;i++)
        if(a[i] == a[i+1]) cnt++;
    if(cnt >= 2) ans = 0; // special judge 3
    if(ans == -1)
    {
        for(int i = 0;i < n;i++)
            step += ((a[i] - i) % 2);
        step %= 2;
        ans = step;
    }
    printf("%s", ans ? "sjfnb" : "cslnb");
    return 0;
}
