#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 505;
const int maxq = 3.2e5;
const int INF = 1e9+7;
int tree[maxn][maxn];
inline int lowbit(int x){return x&-x;}
inline int add(int x, int y, int delta){for(int i = x;i < maxn;i += lowbit(i)) for(int j = y;j < maxn;j += lowbit(j)) tree[i][j] += delta;}
inline int query(int x, int y){int sum = 0;for(int i = x;i > 0;i -= lowbit(i)) for(int j = y;j;j -= lowbit(j)) sum += tree[i][j];return sum;}
struct Cmd{int x1, y1, x2, y2, k, id, is_query;}cmds[maxq], cmdsL[maxq], cmdsR[maxq];
// if the cmd is a change operation, then k is the number and x1 is x, y1 is y
int ans[maxq];
inline int rd()
{
    int f=1, k=0; char c=getchar();
    while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
    while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
    return k*f;
}
void solve(int l, int r, int L, int R)
{
    if(l > r || L > R) return;
    if(l == r)
    {
        for(int i = L;i <= R;i++)
            if(cmds[i].is_query)
                ans[cmds[i].id] = l;
        return;
    }
    int mid = l + r >> 1, cntL = 0, cntR = 0;
    for(int i = L;i <= R;i++)
    {
        if(cmds[i].is_query){
            int k2 = query(cmds[i].x2, cmds[i].y2) - query(cmds[i].x1 - 1, cmds[i].y2) - query(cmds[i].x2, cmds[i].y1 - 1) + query(cmds[i].x1 - 1, cmds[i].y1 - 1);
            if(k2 >= cmds[i].k){
                cmdsL[++cntL] = cmds[i];
            }else{
                cmds[i].k -= k2;
                cmdsR[++cntR] = cmds[i];
            }
        }else{
            if(cmds[i].k <= mid){
                add(cmds[i].x1, cmds[i].y1, 1);
                cmdsL[++cntL] = cmds[i];
            }else{
                cmdsR[++cntR] = cmds[i];
            }
        }
    }
    for(int i = 1;i <= cntL;i++)
        if(cmdsL[i].is_query == 0)
            add(cmdsL[i].x1, cmdsL[i].y1, -1);
    for(int i = 1;i <= cntL;i++)
        cmds[L+i-1] = cmdsL[i];
    for(int i = 1;i <= cntR;i++)
        cmds[L+cntL+i-1] = cmdsR[i];
    solve(    l, mid,      L, L+cntL-1);
    solve(mid+1,   r, L+cntL,        R);
}
int main()
{
    int n = rd(), q = rd(), mx = 0, num, cnt = 0;
    for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
        num = rd(), mx = (mx > num ? mx : num),
        cmds[++cnt] = (Cmd){i, j, 0, 0, num, 0, 0};
    for(int i = 1;i <= q;i++)
        cmds[++cnt] = (Cmd){rd(), rd(), rd(), rd(), rd(), i, 1};
    solve(0, mx, 1, cnt);
    for(int i = 1;i <= q;i++)
        printf("%d\n", ans[i]);
    return 0;
}
