#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
const int maxn = 110;
const int maxm = 1010;
bitset<maxm> facility[maxn];
int G[maxn][maxn];
int color_cnt, color[maxn], color_pos[maxn][maxn];
inline int rd(){int a;scanf("%d", &a);return a;}
void init()
{
    color_cnt = 1;
    memset(color, 0, sizeof(color));
    memset(color_pos, 0, sizeof(color_pos));
    memset(G, 0, sizeof(G));
    for(int i = 0;i < maxn;i++)
        facility[i].reset();
}
int main()
{
    for(int T = rd();T;T--)
    {
        init();
        int n, k;
        n = rd();
        k = rd();
        for(int i = 1;i <= n;i++)
            for(int m = rd();m;m--)
                facility[i].set(rd());
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                G[i][j] = G[j][i] = ((facility[i] & facility[j]).count() > 0) ? 1 : 0;

        int q[maxn], in_q[maxn];
        for(int i = 1;i <= n;i++)
        {
            if(color[i]) continue;
            memset(q, 0, sizeof(q));
            memset(in_q, 0, sizeof(in_q));
            int head = 0, tail = 1;
            q[head] = i;
            while(head < tail)
            {
                int u = q[head++];
                for(int c = 1;c <= color_cnt && color[u] == 0;c++)
                    if(color_pos[u][c] != -1)
                        color[u] = c;
                if(color[u] == 0)
                    color[u] = ++color_cnt;
                for(int v = 1;v <= n;v++)
                {
                    if(G[u][v] == 0) continue;
                    if(color[v]) continue;
                    color_pos[v][color[u]] = -1;
                    if(in_q[v] == 0)
                        q[tail++] = v;
                    in_q[v] = 1;
                }
            }
        }
        printf("%lld\n", 1LL * color_cnt * k);
    }
    return 0;
}