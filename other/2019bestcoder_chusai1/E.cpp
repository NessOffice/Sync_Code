#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
    LL T;
    scanf("%I64d", &T);
    while(T--)
    {
        LL n, ans;
        scanf("%I64d", &n);

        switch (n % 6)
        {
            case 0: ans = n / 2; break;
            case 1: ans = n / 6 * 4 + 1; break;
            case 2: ans = n / 2; break;
            case 3: ans = n / 6; break;
            case 4: ans = n - 1; break;
            case 5: ans = n / 6; break;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
