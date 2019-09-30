#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 2e6+5;
struct Node{int id, di;}node[maxn];
bool cmp(const Node &lhs, const Node &rhs){return lhs.di > rhs.di;}
int n, pos2id[maxn], id2pos[maxn];
int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &node[i].di),
        node[i].id = i;
    sort(node+1, node+n+1, cmp);
    pos2id[1] = node[1].id*2-1;
    id2pos[node[1].id*2-1] = 1;
    for(int i = 2;i <= node[1].di;i++)
    {
        printf("%d %d\n", pos2id[i-1], node[i].id*2-1);
        pos2id[i] = node[i].id*2-1;
        id2pos[node[i].id*2-1] = i;
    }
    printf("%d %d\n", node[1].id*2, pos2id[node[1].di]);
    pos2id[node[1].di+1] = node[1].id*2;
    for(int i = 2;i <= n;i++)
    {
        if(id2pos[node[i].id*2-1]){
            printf("%d %d\n", node[i].id*2, pos2id[id2pos[node[i].id*2-1] + node[i].di - 1]);
            if(pos2id[id2pos[node[i].id*2-1] + node[i].di] == 0)
                pos2id[id2pos[node[i].id*2-1] + node[i].di] = node[i].id*2;
        }else{
            printf("%d %d\n", node[i].id*2, pos2id[1]);
            if(node[i].di == 1)
                printf("%d %d\n", node[i].id*2-1, node[i].id*2);
            else
                printf("%d %d\n", node[i].id*2-1, pos2id[node[i].di-1]);
        }
    }
    return 0;
}
