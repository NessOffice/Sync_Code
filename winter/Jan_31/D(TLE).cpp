#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;
int L[maxm], R[maxm], q[maxm];
int ans_mark[maxn], ans_max[maxn], ans_min[maxn];
int mark_L[maxn], mark_R[maxn];
int sum[maxn], nearest[maxn], terminal[maxn];
int n, m;
void print_min()
{
    for(int j = 1;j <= n;j++)
    {
        if(j > 1)
            putchar(' ');
        printf("%d", ans_min[j]);
    }
    putchar('\n');
}
void print_max()
{
    for(int j = 1;j <= n;j++)
    {
        if(j > 1)
            putchar(' ');
        printf("%d", ans_max[j]);
    }
    putchar('\n');
}
bool check_ok(int i)
{
    for(int j = 0;j < m;j++)
    {
        int qi = (q[j] >> i) & 1;
        if(qi)
        {
            if(sum[R[j]] - sum[L[j]-1] == R[j] - L[j] + 1)
                return false;
        }
    }
    return true;
}
void mark_regions(int i)
{
    for(int j = 0;j < m;j++)
    {
        int qi = (q[j] >> i) & 1;
        if(qi == 0)
        {
            mark_L[L[j]]++;
            mark_R[R[j]]++;
        }
    }
}
void find_nearest()
{
    int last = 0;
    for(int j = 1;j <= n;j++)
    {
        if(ans_mark[j] > 0)
            last = j;
        nearest[j] = last;
    }
}
void mark_terminals(int i)
{
    for(int j = 0;j < m;j++)
    {
        int qi = (q[j] >> i) & 1;
        if(qi)
            terminal[R[j]] = max(terminal[R[j]], L[j]);
    }
}
void find_max(int i)
{
    int mark_temp = 0;
    for(int j = 1;j <= n;j++)
    {
        sum[j] = sum[j-1];
        mark_temp += mark_L[j];
        if(mark_temp > 0){ // this indicates that this bit should be '0'
            ans_mark[j] = 0;
            sum[j]++;
        }else
            ans_max[j] += (1 << i);
        mark_temp -= mark_R[j];
    }
}
void find_min(int i)
{
    int last = 0;
    for(int j = 1;j <= n;j++)
        if(terminal[j] > last)
        {
            int j2 = nearest[j];
            if(ans_mark[j2] < 2 )
            {
                last = j2;
                ans_mark[j2] = 2;
                ans_min[j2] += (1 << i);
            }
        }
}
void init()
{
    for(int j = 0;j <= n;j++)
    {
        ans_mark[j] = 1;
        mark_L[j] = 0;
        mark_R[j] = 0;
        sum[j] = 0;
        terminal[j] = 0;
        nearest[j] = 0;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0;i < m;i++)
            scanf("%d%d%d", &L[i], &R[i], &q[i]);
        bool ok = true;
        for(int i = 0;i <= n;i++)
            ans_max[i] = ans_min[i] = 0;
        for(int i = 0;i < 30;i++)
        {
            init();
            mark_regions(i);
            find_max(i);
            ok = check_ok(i);
            if(!ok) break;
            find_nearest();
            mark_terminals(i);
            find_min(i);
        }
        printf("%s\n", ok ? "come on, nice girl!" : "I am a poor guy!");
        if(ok)
        {
            print_min();
            print_max();
        }
    }
    return 0;
}