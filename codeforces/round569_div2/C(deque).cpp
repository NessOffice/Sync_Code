#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 5;
struct Query{int index, ans1, ans2;long long round;}queries[maxn];
bool cmp_by_round(const Query& lhs, const Query& rhs){return lhs.round < rhs.round;}
bool cmp_by_index(const Query& lhs, const Query& rhs){return lhs.index < rhs.index;}
int main()
{
    deque<int> a;
    int n, q, maxv = 0;
    scanf("%d%d", &n, &q);
    for(int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
        if(a[i] > a[maxv]) maxv = i;
    }
    for(int i = 0;i < q;i++)
    {
        scanf("%lld", &queries[i].round);
        queries[i].index = i;
    }
    sort(queries, queries + q, cmp_by_round);
    int index_query = 0;
    for(int i = 0;i < maxv;i++)
    {
        int A = a[0], B = a[1];
        a.pop_front();
        a.pop_front();
        while(1LL*i == queries[index_query].round - 1)
        {
            queries[index_query].ans1 = A;
            queries[index_query].ans2 = B;
            index_query++;
        }
        if(A < B) swap(A, B);
        a.push_front(A);
        a.push_back(B);
    }
    while(index_query < q)
    {
        long long temp_round = queries[index_query].round - maxv;
        queries[index_query].ans1 = a[0];
        queries[index_query].ans2 = a[int((temp_round-1) % (n-1) + 1)];
        index_query++;
    }
    sort(queries, queries + q, cmp_by_index);
    for(int i = 0;i < q;i++)
        printf("%d %d\n", queries[i].ans1, queries[i].ans2);
    return 0;
}
