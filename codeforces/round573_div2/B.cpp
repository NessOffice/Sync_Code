#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
struct Node{int num; char hua;}nodes[5];
bool cmp(const Node& lhs, const Node& rhs){return lhs.num < rhs.num;}
bool same_color(int i, int j){return nodes[i].hua == nodes[j].hua;}
bool near(int i, int j, int v){return nodes[i].num + v == nodes[j].num;}
int main()
{
    char s[4];
    for(int i = 0;i < 3;i++)
    {
        scanf("%s", s);
        nodes[i].num = s[0];
        nodes[i].hua = s[1];
    }
    sort(nodes, nodes + 3, cmp);
    int ans = -1;
    if(same_color(0, 1) && same_color(0, 2) && near(0, 1, 0) && near(0, 2, 0)) ans = 0;
    if(same_color(0, 1) && same_color(0, 2) && near(0, 1, 1) && near(1, 2, 1)) ans = 0;
    if(ans == -1)
    {
        if(same_color(0, 1) && (near(0, 1, 0) || near(0, 1, 1) || near(0, 1, 2))) ans = 1;
        if(same_color(1, 2) && (near(1, 2, 0) || near(1, 2, 1) || near(1, 2, 2))) ans = 1;
        if(same_color(0, 2) && (near(0, 2, 0) || near(0, 2, 1) || near(0, 2, 2))) ans = 1;
    }
    if(ans == -1) ans = 2;
    printf("%d", ans);
    return 0;
}
