#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
int num[200], vis[200], cnt;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &num[i]);
    sort(num, num + n);
    for(int i = 0;i < n;i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        cnt++;
        for(int j = i;j < n;j++)
            if(num[j] % num[i] == 0)
                vis[j] = true;
    }
    printf("%d", cnt);
    return 0;
}