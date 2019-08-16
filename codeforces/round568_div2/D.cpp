#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2e5 + 5; // caution
LL n;
struct Node{LL num, index;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.num < rhs.num;}
void solve()
{
    if(n <= 3){
        printf("1");
        return;
    }else{
        LL j;
        for(j = 2;j < n;j++)
            if(nodes[j].num - nodes[j-1].num != nodes[2].num - nodes[1].num) break;
        if(j == n){printf("%lld", nodes[0].index);return;}

        for(j = 1;j < n-1;j++)
            if(nodes[j].num - nodes[j-1].num != nodes[1].num - nodes[0].num) break;
        if(j == n-1){printf("%lld", nodes[n-1].index);return;}

        for(j = 3;j < n;j++)
            if(nodes[j].num - nodes[j-1].num != nodes[2].num - nodes[0].num) break;
        if(j == n){printf("%lld", nodes[1].index);return;}

        LL mark = -1;
        for(j = 2;j < n-1;j++)
            if(nodes[j].num - nodes[j-1].num != nodes[1].num - nodes[0].num)
            {
                if(nodes[j+1].num - nodes[j-1].num == nodes[1].num - nodes[0].num){
                    if(mark == -1)
                        mark = j++;
                    else{
                        printf("-1");
                        return;
                    }
                }else{
                    printf("-1");
                    return;
                }
            }
        if(mark != -1)
            printf("%lld", nodes[mark].index);
    }
}
int main()
{
    scanf("%lld", &n);
    for(LL i = 0;i < n;i++)
    {
        scanf("%lld", &nodes[i].num);
        nodes[i].index = i+1;
    }
    sort(nodes, nodes + n, cmp);
    solve();
    return 0;
}
