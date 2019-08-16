#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int sum(int num)
{
    if(num < 10) return num;
    return num % 10 + sum(num / 10);
}
int main()
{
    int a;
    scanf("%d", &a);
    while(sum(a) % 4)
        a++;
    printf("%d", a);
    return 0;
}
