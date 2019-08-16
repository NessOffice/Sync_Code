#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int maxn = 2e3 + 5;
using namespace std;
struct Node{int l, r;}sections[maxn];
bool cmp(const Node& lhs, const Node& rhs){return lhs.l < rhs.l;}
int L[maxn], R[maxn], t[maxn];
int color[maxn], color_cnt, sec_cnt;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d", &t[i], &L[i], &R[i]);
        if(t[i])
        {
            sections[sec_cnt].l = L[i];
            sections[sec_cnt].r = R[i];
            sec_cnt++;
        }
    }
    sort(sections, sections+sec_cnt, cmp);
    for(int now = 0;now < sec_cnt;now++)
    {
        int color_now = ++color_cnt;
        for(int j = sections[now].l;j <= sections[now].r;j++)
            if(color[j]) color_now = color[j];
        for(int j = sections[now].l;j <= sections[now].r;j++)
            color[j] = color_now;
    }
    bool flag = true;
    for(int i = 0;i < m;i++)
    {
        if(t[i]) continue;
        bool one_color = true;
        for(int j = L[i]+1;j <= R[i] && one_color;j++)
            if(color[j] != color[j-1]) one_color = false;
        if(color[L[i]] == 0) one_color = false;
        flag = !one_color;
    }
    printf("%s\n", flag ? "YES" : "NO");
    if(flag)
    {
        int now = maxn;
        for(int i = 1;i <= n;i++)
        {
            if(color[i] != color[i-1]) now--;
            printf("%d ", now);
        }
    }
    return 0;
}
/*
7 2
1 1 3
0 1 3
*/