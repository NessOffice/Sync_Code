#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
int turn(int dir_now, int dir_turn)
{
    if(dir_now == 0 && dir_turn == 1) return 2;
    if(dir_now == 0 && dir_turn == -1) return 3;
    if(dir_now == 1 && dir_turn == 1) return 3;
    if(dir_now == 1 && dir_turn == -1) return 2;
    if(dir_now == 2 && dir_turn == 1) return 1;
    if(dir_now == 2 && dir_turn == -1) return 0;
    if(dir_now == 3 && dir_turn == 1) return 0;
    if(dir_now == 3 && dir_turn == -1) return 1;
}
int main()
{
    int n, len, dir_turn, ans[20000];
    scanf("%d", &n);
    int dir_now = 0, len_hori = 0, len_vert = 0;
    int dir_hori = 0, dir_vert = 2;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d", &len, &dir_turn);
        int len_new = 1;
        if(dir_now < 2)
        {
            if(dir_now == dir_hori)
            {
                len_new = ++len_hori;
                dir_hori = 1^dir_now;
            }
            else
                len_hori++;
        }
        if(dir_now >= 2)
        {
            if(dir_now == dir_vert)
            {
                len_new = ++len_vert;
                dir_vert = 1^(dir_now-2)+2;
            }
            else
                len_vert++;
        }
        ans[i] = len_new;
        dir_now = turn(dir_now, dir_turn);
    }
    for(int i = 1;i <= n;i++)
        printf("%d ", ans[i]);
    return 0;
}
/*
6
4 1
5 -1
2 -1
2 -1
4 1
5 0

6
3 1
3 1
2 1
4 1
1 1
3 0
*/