#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
struct Node{int cnt, keep;}nodes[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.cnt < rhs.cnt || (lhs.cnt == rhs.cnt && lhs.keep < rhs.keep);}
map<int, int> id;
int q, n, id_cnt;
int main()
{
    scanf("%d", &q);
    while(q--)
    {
        id_cnt = 0;
        id.clear();
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
            nodes[i].cnt = nodes[i].keep = 0;
        for(int i = 0;i < n;i++)
        {
            int ai, fi;
            scanf("%d%d", &ai, &fi);
            if(id.count(ai) == 0)
                id[ai] = id_cnt++;
            nodes[id[ai]].cnt++;
            nodes[id[ai]].keep += fi;
        }
        sort(nodes, nodes+id_cnt, cmp);
        int ans1 = 0, ans2 = 0, cnt_last = nodes[id_cnt-1].cnt;
        int node_now = id_cnt-1, node_next = id_cnt-1;
        while(cnt_last > 0 && node_now >= 0)
        {
            if(cnt_last == nodes[node_now].cnt){
                ans1 += cnt_last;
                ans2 += min(cnt_last, nodes[node_now].keep);
                node_now--;
                cnt_last--;
            }else if(cnt_last < nodes[node_now].cnt){
                if(node_next > node_now) node_next = node_now;
                while(node_next >= 0 && nodes[node_next].cnt >= cnt_last)
                {
                    if(nodes[node_next].keep > nodes[node_now].keep) break;
                    node_next--;
                }
                if(nodes[node_next].cnt < cnt_last) node_next++;
                if(nodes[node_next].keep > nodes[node_now].keep)
                    node_now = node_next;
                nodes[node_now].cnt = cnt_last;
            }else cnt_last = nodes[node_now].cnt;
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
