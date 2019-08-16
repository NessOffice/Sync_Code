#include <cstdio>
#include <cstring>
const int maxn = (1 << 18) + 5;
int n, x, len = 0, prefix[maxn], vis[maxn];
int main()
{
    memset(prefix, 0, sizeof(prefix));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &x);
    if(x >= (1 << n))
    {
        len = (1 << n);
        for(int i = 1;i < len;i++)
            prefix[i] = i;
    }
    else
    {
        vis[x] = 1;
        int last = 1;
        len = (1 << (n-1));
        for(int i = 1;i < len;i++)
        {
            while(last < (len<<1) && vis[last]) last++;
            prefix[i] = last;
            vis[last] = vis[x^last] = 1;
            last++;
        }
    }
    printf("%d\n", len-1);
    for(int i = 1;i < len;i++)
        printf("%d ", prefix[i] ^ prefix[i-1]);
    return 0;
}
