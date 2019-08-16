#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
int main()
{
    int x;
    scanf("%d", &x);
    if(x % 4 == 1) printf("0 A");
    if(x % 4 == 2) printf("1 B");
    if(x % 4 == 3) printf("2 A");
    if(x % 4 == 0) printf("1 A");
    return 0;
}
