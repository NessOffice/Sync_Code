#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int ans[100] = {0, 287, 311, 80, 96, 609, 675, 76, 315, 543, 455, 351, 342, 188, 204, 286, 47, 0, 175, 55, 94, 630, 516, 69, 431, 364, 615, 171, 177, 252, 116, 172, 55, 175, 0, 47, 69, 516, 630, 94, 171, 615, 364, 431, 172, 116, 252, 177, 80, 311, 287, 0, 76, 675, 609, 96, 351, 455, 543, 315, 286, 204, 188, 342};
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", ans[16*(a-1)+4*(b-1)+(c-1)]);
    return 0;
}
