#include <cstdio>
#include <algorithm>
const int maxn = 1e4 + 5;
int a[maxn], n, m;
void next_permutation()
{
    int j = n-1, k = n;
    while(a[j] > a[j+1]) j--;
    while(a[j] > a[k]) k--;
    std::swap(a[j], a[k]);
    j++, k = n;
    while(k > j){std::swap(a[j], a[k]);k--;j++;}
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    while(m--)
        next_permutation();
    printf("%d", a[1]);
    for(int i = 2;i <= n;i++)
        printf(" %d", a[i]);
}
