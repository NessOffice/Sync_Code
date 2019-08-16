#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
char grids[maxn][maxn];
int length_color[maxn][maxn];
int n, m;
long long ans = 0LL;
bool check(int i, int j, int j2)
{
    if(grids[i][j] != grids[i][j2]) return false;
    if(length_color[i][j] != length_color[i][j2]) return false;

    int i2 = i + length_color[i][j];
    if(i2 > n) return false;
    if(grids[i2][j] != grids[i2][j2]) return false;
    if(length_color[i2][j] != length_color[i2][j2]) return false;

    int i3 = i2 + length_color[i2][j];
    if(i3 > n) return false;
    if(grids[i3][j] != grids[i3][j2]) return false;

    if(length_color[i][j] != length_color[i2][j]) return false;
    if(length_color[i][j] > length_color[i3][j]) return false; // caution!!!
    if(length_color[i][j] > length_color[i3][j2]) return false;

    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%s", grids[i]);
    for(int j = 0;j < m;j++)
    {
        int head = 0, node = 0;
        while(head < n)
        {
            while(node < n && grids[head][j] == grids[node][j])
                node++;
            for(;head < node;head++)
                length_color[head][j] = node - head;
        }
    }
    for(int i = 0;i < n;i++)
    {
        int head = 0, node = 0;
        while(head < m)
        {
            while(node < m && check(i, head, node))
                node++;
            int len = (node - head);
            ans += (1LL * len * (len+1) / 2);
            if(len == 0)
                node++;
            head = node;
        }
    }
    printf("%lld", ans);
    return 0;
}