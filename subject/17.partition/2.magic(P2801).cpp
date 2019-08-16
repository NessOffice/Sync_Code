#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
const int sqrtmaxn = 1e3+5;
int val[sqrtmaxn][sqrtmaxn], mark[sqrtmaxn];
int main()
{
    int n, m, sz, sz_lst, num_of_blocks;
    scanf("%d%d", &n, &m);
    sz = pow(n, 0.5);
    for(int i = 0;i < n;i++)
        scanf("%d", &val[i/sz][i%sz]);
    num_of_blocks = (n-1)/sz + 1;
    sz_lst = sz*num_of_blocks - n;
    if(sz_lst == 0) sz_lst = sz;
    for(int i = 0;i < num_of_blocks;i += sz)
        sort(val[i], val[i] + (i == num_of_blocks-1 ? sz_lst : sz));
    while(m--)
    {
        char cmd_str[3];
        int l, r, delta;
        scanf("%s%d%d%d", cmd_str, &l, &r, &delta);
        int block_l = (l-1)/sz+1, block_r = (r-1)/sz+1;
    }
    return 0;
}
