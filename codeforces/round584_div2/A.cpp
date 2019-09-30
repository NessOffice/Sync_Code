#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
int color[200], cnt;
int main()
{
    bool flag = false;
    int n, num;
    scanf("%d", &n);
    scanf("%d", &color[1]), cnt = 1;
    for(int i = 1;i < n;i++)
    {
        scanf("%d", &num);
        if(num == 1) flag = true;
        int j;
        for(j = 1;j <= cnt;j++)
        {
            if(num % color[j] == 0 || color[j] % num == 0)
            {
                color[j] = min(color[j], num);
                break;
            }
        }
        if(j > cnt)
            color[++cnt] = num;
    }
    if(flag) cnt = 1;
    printf("%d", cnt);
    return 0;
}