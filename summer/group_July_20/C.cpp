#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 5;
int main()
{
    LL V, S = (LL)(1e15);
    scanf("%lld", &V);
    for(LL a = 1;a*a*a <= V;a++)
    for(LL b = a;a*b*b <= V;b++)
    {
        LL c = V/a/b;
        if(a*b*c != V) continue;
        S = min(S, 2*(a*b+b*c+c*a));
    }
    printf("%lld", S);
    return 0;
}
