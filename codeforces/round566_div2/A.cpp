#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
    scanf("%d", &n);
    if(n % 2) printf("0");
    else printf("%lld", 1ll << (n / 2)); // fuck
    return 0;
}
