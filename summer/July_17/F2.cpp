#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 6005;
int x[maxn], y[maxn];
int color[maxn], ans[maxn], cnt;
int color2index[2][maxn], cnt_of_color[2], mini_index[2];
map<pair<int, int>, int> loc;
set<int> res;
struct Node
{
    int minimal, delta;
    vector<int> sel;
    vector<int> not_sel;
    bool operator< (const Node& rhs){return minimal < rhs.minimal;}
};
vector<Node> upd;
void bfs(int i)
{
    if(color[i] != -1) return;
    mini_index[0] = i;
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
            mini_index[c^1] = min(mini_index[c^1], v);
            q.push(v);
        }
        if(loc.count(make_pair(x2, y2)) && color[loc[make_pair(x2, y2)]] == -1)
        {
            int v = loc[make_pair(x2, y2)];
            color[v] = c^1;
            color2index[c^1][cnt_of_color[c^1]++] = v;
            mini_index[c^1] = min(mini_index[c^1], v);
            q.push(v);
        }
        if(loc.count(make_pair(x3, y3)) && color[loc[make_pair(x3, y3)]] == -1)
        {
            int v = loc[make_pair(x3, y3)];
            color[v] = c^1;
            color2index[c^1][cnt_of_color[c^1]++] = v;
            mini_index[c^1] = min(mini_index[c^1], v);
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
        mini_index[0] = mini_index[1] = maxn;
        bfs(i);
        int c = (cnt_of_color[1] > cnt_of_color[0] ? 1 : 0);
        if(mini_index[c] > mini_index[c^1])
        {
            Node node;
            node.delta = cnt_of_color[c] - cnt_of_color[c^1];
            node.minimal = mini_index[c^1];
            for(int j = 0;j < cnt_of_color[c];j++)
                node.sel.push_back(color2index[c][j]);
            for(int j = 0;j < cnt_of_color[c^1];j++)
                node.not_sel.push_back(color2index[c^1][j]);
            upd.push_back(node);
        }
        for(int j = 0;j < cnt_of_color[c];j++)
        {
            cnt++;
            res.insert(color2index[c][j]);
        }
    }
    if(cnt < m) printf("-1");
    else
    {
        sort(upd.begin(), upd.end());
        for(int i = 0, sz_of_upd = upd.size();i < sz_of_upd;i++)
        {
            if(cnt - m >= upd[i].delta)
            {
                for(int j = 0, sz_of_sel = upd[i].sel.size();j < sz_of_sel;j++)
                    res.erase(upd[i].sel[j]);
                for(int j = 0, sz_of_notsel = upd[i].not_sel.size();j < sz_of_notsel;j++)
                    res.insert(upd[i].not_sel[j]);
                cnt -= upd[i].delta;
            }
        }
        int zz = 0;
        for(set<int>::iterator iter = res.begin();iter != res.end() && zz < m;iter++)
        {
            printf("%d\n", *iter);
            zz++;
        }
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