#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 6005;
int x[maxn], y[maxn];
int color[maxn], ans[maxn], cnt;
int color2index[2][maxn], cnt_of_color[2];
map<pair<int, int>, int> loc;
void bfs(int i)
{
    if(color[i] != -1) return;
    color[i] = 0;
    color2index[0][cnt_of_color[0]++] = i;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        int c = color[u];
        int x0 = x[u], y0 = y[u];
        int x1 = x[u], y1 = y[u];
        int x2 = x[u]-1, y2 = y[u];
        int x3 = x[u]+1, y3 = y[u];
        if(y0 % 4 == 1 || y0 % 4 == 3){y1--;y2++;y3++;}
        if(y0 % 4 == 0 || y0 % 4 == 2){y1++;y2--;y3--;}
        if(loc.count(make_pair(x1, y1)) && color[loc[make_pair(x1, y1)]] == -1)
        {
            int v = loc[make_pair(x1, y1)];
            color[v] = c^1;
            color2index[c^1][cnt_of_color[c^1]++] = v;
            q.push(v);
        }
        if(loc.count(make_pair(x2, y2)) && color[loc[make_pair(x2, y2)]] == -1)
        {
            int v = loc[make_pair(x2, y2)];
            color[v] = c^1;
            color2index[c^1][cnt_of_color[c^1]++] = v;
            q.push(v);
        }
        if(loc.count(make_pair(x3, y3)) && color[loc[make_pair(x3, y3)]] == -1)
        {
            int v = loc[make_pair(x3, y3)];
            color[v] = c^1;
            color2index[c^1][cnt_of_color[c^1]++] = v;
            q.push(v);
        }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d", x+i, y+i);
        loc[make_pair(x[i], y[i])] = i;
        color[i] = -1;
    }
    for(int i = 1;i <= n;i++)
    {
        cnt_of_color[0] = cnt_of_color[1] = 0;
        bfs(i);
        int c = (cnt_of_color[1] > cnt_of_color[0] ? 1 : 0);
        for(int j = 0;j < cnt_of_color[c];j++)
            ans[cnt++] = color2index[c][j];
    }
    if(cnt < m) printf("-1");
    else
    {
        sort(ans, ans+m);
        for(int i = 0;i < m;i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
/*
4 3
1 3
2 1
1 2
5 2

2 2
5 6
6 5
*/