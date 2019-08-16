#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int grids[3][maxn], group[maxn];
int main()
{
    bool ans = true;
    int n;
    scanf("%d", &n);
    for(int i = 0;i < 3;i++)
    for(int j = 0;j < n;j++)
    {
        scanf("%d", &grids[i][j]);
        if(i != 1 && grids[i][j] % 3 == 2) ans = false;
        if(i == 1 && grids[i][j] % 3 != 2) ans = false;
        if(i == 1 && grids[i][j] % 6 != 3*(j%2)+2) ans = false;
    }
    printf("%s", ans ? "Yes" : "No");
    return 0;
}
/*
5
9 6 15 12 1
8 5 14 11 2
7 4 13 10 3
*/