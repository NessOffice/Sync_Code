#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
const int INF = 1e9+7;
int rd(){int x;scanf("%d", &x);return x;}
int tree[maxn];
int lowbit(int x){return x&-x;}
int add(int begin, int delta){for(int i = begin;i < maxn;i += lowbit(i)) tree[i] += delta;}
int query(int begin){int sum = 0;for(int i = begin;i > 0;i -= lowbit(i)) sum += tree[i];return sum;}
struct Cmd{int a, b, k, id, num, is_query;}cmds[maxn + 5005], cmdsL[maxn + 5005], cmdsR[maxn + 5005];
int ans[5005];
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
            int k2 = query(cmds[i].b) - query(cmds[i].a - 1);
            if(k2 >= cmds[i].k){
                cmdsL[++cntL] = cmds[i];
            }else{
                cmds[i].k -= k2;
                cmdsR[++cntR] = cmds[i];
            }
        }else{
            if(cmds[i].num <= mid){
                add(cmds[i].id, 1);
                cmdsL[++cntL] = cmds[i];
            }else{
                cmdsR[++cntR] = cmds[i];
            }
        }
    }
    for(int i = 1;i <= cntL;i++)
        if(cmdsL[i].is_query == 0)
            add(cmdsL[i].id, -1);
    for(int i = 1;i <= cntL;i++)
        cmds[L+i-1] = cmdsL[i];
    for(int i = 1;i <= cntR;i++)
        cmds[L+cntL+i-1] = cmdsR[i];
    solve(    l, mid,      L, L+cntL-1);
    solve(mid+1,   r, L+cntL,        R);
}
int main()
{
    int n = rd(), m = rd(), cnt = 0;
    for(int i = 1;i <= n;i++)
        cmds[++cnt] = (Cmd){0, 0, 0, i, rd(), 0};
    for(int i = 1;i <= m;i++)
        cmds[++cnt] = (Cmd){rd(), rd(), rd(), i, 0, 1};
    solve(-INF, INF, 1, cnt);
    for(int i = 1;i <= m;i++)
        printf("%d\n", ans[i]);
    return 0;
}
