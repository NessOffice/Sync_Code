#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {2, 4, 4, 6, 8};
    printf("same: %d\n", lower_bound(a, a+5, 7)-a);
    return 0;
}