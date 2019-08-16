#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int grids[maxn][3], group[maxn], loc[maxn];
int calc(int col1, int col2, int col3)
{
    int num = 0;
    if(col1 % 3 == 0)
    if(col2 == col1 - 1)
    if(col3 == col2 - 1)
        num = -col1/3;
    if(col3 % 3 == 0)
    if(col2 == col3 - 1)
    if(col1 == col2 - 1)
        num = col3/3;
    return num;
}
void operate(int center)
{
    swap(group[center-1], group[center+1]);
    swap(loc[abs(group[center-1])], loc[abs(group[center+1])]);
    group[center-1] *= -1;
    group[center+1] *= -1;
    group[center] *= -1;
}
int main()
{
    bool ans = true;
    int n;
    scanf("%d", &n);
    for(int j = 0;j < 3;j++)
    for(int i = 1;i <= n;i++)
        scanf("%d", &grids[i][j]);
    for(int i = 1;i <= n;i++)
    {
        group[i] = calc(grids[i][0], grids[i][1], grids[i][2]);
        loc[abs(group[i])] = i;
        if(group[i] == 0) ans = false;
        if(abs(group[i]) % 2 != i % 2) ans = false;
    }
    for(int i = 1;i < n && ans;i++)
    {
        if(loc[i] == 0){ans = false;break;}
        while(loc[i] != i)
            operate(loc[i]-1);
        if(group[i] < 0)
        {
            if(i+3 > n) ans = false;
            else
            {
                group[i] *= -1;
                group[i+1] *= -1;
                group[i+2] *= -1;
                group[i+3] *= -1;
            }
        }
    }
    printf("%s", ans ? "Yes" : "No");
    return 0;
}
/*
5
9 6 15 12 1
8 5 14 11 2
7 4 13 10 3

5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
*/