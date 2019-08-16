#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 6005;
int x[maxn], y[maxn];
int vis[maxn], ans[maxn], cnt;
int color2index[2][maxn], cnt_of_color[2];
map<pair<int, int>, int> loc;
void dfs(int i, int c)
{
    if(vis[i]) return;
    vis[i] = 1;
    color2index[c][cnt_of_color[c]++] = i;
    int x0 = x[i], y0 = y[i];
    int x1 = x[i], y1 = y[i];
    int x2 = x[i]-1, y2 = y[i];
    int x3 = x[i]+1, y3 = y[i];
    if(y0 % 4 == 1 || y0 % 4 == 3){y1--;y2++;y3++;}
    if(y0 % 4 == 0 || y0 % 4 == 2){y1++;y2--;y3--;}
    if(loc.count(make_pair(x1, y1))) dfs(loc[make_pair(x1, y1)], c^1);
    if(loc.count(make_pair(x2, y2))) dfs(loc[make_pair(x2, y2)], c^1);
    if(loc.count(make_pair(x3, y3))) dfs(loc[make_pair(x3, y3)], c^1);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d", x+i, y+i);
        loc[make_pair(x[i], y[i])] = i;
        vis[i] = 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cnt_of_color[0] = cnt_of_color[1] = 0;
        dfs(i, 0);
        int c = (cnt_of_color[1] > cnt_of_color[0] ? 1 : 0);
        for(int j = 0;j < cnt_of_color[c];j++)
            ans[cnt++] = color2index[c][j];
    }
    if(cnt < m) printf("-1");
    else for(int i = 0;i < m;i++)
            printf("%d\n", ans[i]);
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