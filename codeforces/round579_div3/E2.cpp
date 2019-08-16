#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1.5e5+5;
int a[maxn], b[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int num;
        scanf("%d", &num);
        a[num]++;
    }
    for(int i = 150000;i >= 1;i--)
    {
        if(a[i] >= 3) b[i-1] = b[i] = b[i+1] = 1;
        if(a[i] == 2)
        {
            b[i] = 1;
            if(b[i+1]) b[i-1] = 1;
            else b[i+1] = 1;
        }
        if(a[i] == 1)
        {
            if(!b[i+1]) b[i+1] = 1;
            else if(b[i]) b[i-1] = 1;
            else b[i] = 1;
        }
    }
    int ans = 0;
    for(int i = 1;i <= 150001;i++)
        if(b[i]) ans++;
    printf("%d", ans);
    return 0;
}
