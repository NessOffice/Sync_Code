#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 7e4+5; // caution!!!
const int INF = 1e9+7;
int rd(){int x;scanf("%d", &x);return x;}
int tree[maxn];
int lowbit(int x){return x&-x;}
int add(int begin, int delta){for(int i = begin;i < maxn;i += lowbit(i)) tree[i] += delta;}
int query(int begin){int sum = 0;for(int i = begin;i > 0;i -= lowbit(i)) sum += tree[i];return sum;}
struct Cmd{int a, b, k, id, is_query;}cmds[maxn], cmds_L[maxn], cmds_R[maxn];
int num[maxn], ans[maxn];
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
                cmds_L[++cntL] = cmds[i];
            }else{
                cmds[i].k -= k2;
                cmds_R[++cntR] = cmds[i];
            }
        }else{
            if(cmds[i].a <= mid){ // when cmd is a change operation, a is for the value and b is for +/-
                add(cmds[i].id, cmds[i].b);
                cmds_L[++cntL] = cmds[i];
            }else{
                cmds_R[++cntR] = cmds[i];
            }
        }
    }
    for(int i = 1;i <= cntL;i++)
        if(cmds_L[i].is_query == 0)
            add(cmds_L[i].id, -cmds_L[i].b);
    for(int i = 1;i <= cntL;i++)
        cmds[L+i-1] = cmds_L[i];
    for(int i = 1;i <= cntR;i++)
        cmds[L+cntL+i-1] = cmds_R[i];
    solve(    l, mid,      L, L+cntL-1);
    solve(mid+1,   r, L+cntL,        R);
}
int main()
{
    for(int T = rd();T;T--)
    {
        memset(ans, -1, sizeof(ans));
        int n = rd(), m = rd(), cnt = 0;
        for(int i = 1;i <= n;i++)
            cmds[++cnt] = (Cmd){num[i] = rd(), 1, 0, i, 0};
        for(int i = 1;i <= m;i++)
        {
            char cmd_str[2];
            scanf("%s", cmd_str);
            if(cmd_str[0] == 'Q')
                cmds[++cnt] = (Cmd){rd(), rd(), rd(), i, 1};
            else
            {
                int id = rd();
                cmds[++cnt] = (Cmd){       num[id], -1, 0, id, 0};
                cmds[++cnt] = (Cmd){num[id] = rd(),  1, 0, id, 0};
            }
        }
        solve(0, INF, 1, cnt);
        for(int i = 1;i <= m;i++)
            if(ans[i] != -1)
                printf("%d\n", ans[i]);
    }
    return 0;
}
/*
2
5 3
3 2 1 4 7
Q 1 4 3
C 2 6
Q 2 5 3
5 3
3 2 1 4 7
Q 1 4 3
C 2 6
Q 2 5 3
*/