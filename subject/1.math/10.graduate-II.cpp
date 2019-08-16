#include <cstdio>
#include <algorithm>
const int maxn = 1e6 + 5;
int cnt[maxn];
int main()
{
    int n, num, maxv = 0;
    for(int i = 0;i < maxn;i++)
        cnt[i] = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &num);
        if(num > maxv) maxv = num;
        for(int j = 1;j*j <= num;j++)
        {
            if(num % j) continue;
            cnt[j]++;
            if(j*j < num) cnt[num/j]++;
        }
    }
    /* std::sort(nodes+1, nodes+maxv+1, cmp);
    for(int p = 0, rep = 0;p <= maxv;p++)
        if(p == maxv || nodes[p].cnt != nodes[p+1].cnt)
        {
            while(rep--)
                printf("%d\n", nodes[p].v);
            if(p < maxv) rep = nodes[p+1].cnt - nodes[p].cnt;
        }
        */
    int k = maxv;
    for(int i = 1;i <= n;i++)
    {
        while(cnt[k] < i) k--;
        printf("%d\n", k);
    }
}
