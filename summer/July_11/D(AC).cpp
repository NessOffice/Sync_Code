#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 1e7+5;
int cnt_of_id;
struct Segment{int l, r, id;};
vector<Segment> vec[2];
map<int, int> cnt;
bool is_space(char ch){return ch == ' ' || ch == '\r' || ch == '\n';}
int pre[maxn], sz[maxn];
Segment get_segment(int l, int r, int sz_now, int id)
{
    Segment seg_temp;
    seg_temp.l = l;
    seg_temp.r = r;
    seg_temp.id = id;
    sz[id] = sz_now;
    return seg_temp;
}
int find(int u){return pre[u] == u ? u : (pre[u] = find(pre[u]));}
void join(int u, int v)
{
    if(find(u) != find(v))
    {
        pre[v] = find(u);
        sz[u] += sz[v];
    }
}
char get_char()
{
    char ch = getchar();
    while(is_space(ch)) ch = getchar();
    return ch;
}
void read_line(int now)
{
    int l, r;
    while(1)
    {
        l = r = 0;
        char ch = get_char();
        while(isdigit(ch)){l=l*10+(ch-'0');ch = get_char();}
        if(ch == '-'){
            ch = get_char();
            while(isdigit(ch)){r=r*10+(ch-'0');ch = get_char();}
            vec[now].push_back(get_segment(l, r, r-l+1, ++cnt_of_id)); // and then ch == ',' or ';'
            pre[cnt_of_id] = cnt_of_id;
        }else if(l) // ch == ',' or ';'
            {vec[now].push_back(get_segment(l, l, 1, ++cnt_of_id));pre[cnt_of_id] = cnt_of_id;}
        if(ch == ';') break;
    }
}
bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs){return lhs.first > rhs.first;}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        cnt_of_id = 0;
        cnt.clear();
        vec[0].clear();vec[1].clear();
        int n, now = 1;
        scanf("%d", &n);
        for(int i = 0;i < n;i++)
        {
            read_line(now);
            int len1 = vec[now].size(), len2 = vec[now^1].size();
            int ptr1, ptr2 = 0;
            for(ptr1 = 0;ptr1 < len1;ptr1++)
                while(ptr2 < len2)
                {
                    if(vec[now][ptr1].r < vec[now^1][ptr2].l) break;
                    if(vec[now][ptr1].l > vec[now^1][ptr2].r) ptr2++;
                    else
                    {
                        join(find(vec[now][ptr1].id), find(vec[now^1][ptr2].id));
                        if(vec[now][ptr1].r > vec[now^1][ptr2].r) ptr2++;
                        else break;
                    }
                }
            vec[now^1].clear();
            now ^= 1;
        }
        for(int id = 1;id <= cnt_of_id;id++)
            if(pre[id] == id) cnt[sz[id]]++;
        vector<pair<int, int> > ans;
        for(map<int, int>::iterator iter = cnt.begin();iter != cnt.end();iter++)
            ans.push_back(make_pair(iter->first, iter->second));
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0, len = ans.size();i < len;i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
/*
2
8
2,4-5;
5-6;
2-3,6;
6-7;
;
2-4;
2,4,6-7;
2-3,6-7;
2
1;
;

1
4
2,4-5;
5-6;
2-3,6;
6-7;
*/