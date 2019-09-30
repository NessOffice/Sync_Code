#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
int vis[10];
bool check(int x)
{
    memset(vis, 0, sizeof(vis));
    do{
        if(vis[x % 10])
            return false;
        vis[x % 10]++;
        x /= 10;
    }while(x);
    return true;
}
int main()
{
    int l, r;
    bool ok = false;
    scanf("%d%d", &l, &r);
    for(int i = l;i <= r && !ok;i++)
    {
        if(check(i))
            ok = true,
            printf("%d\n", i);
    }
    if(!ok) printf("%d\n", -1);
    return 0;
}