#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5 + 5;
struct Node{int value;struct Node *next;}*head = NULL, *tail;
struct Query{int index, ans1, ans2;long long round;}queries[maxn];
bool cmp_by_round(const Query& lhs, const Query& rhs){return lhs.round < rhs.round;}
bool cmp_by_index(const Query& lhs, const Query& rhs){return lhs.index < rhs.index;}
int a[maxn], b[maxn];
int main()
{
    int n, q, maxv = 0;
    scanf("%d%d", &n, &q);
    struct Node *last = NULL;
    for(int i = 0;i < n;i++)
    {
        scanf("%d", a + i);
        struct Node *node = (Node*)malloc(sizeof(Node));
        node->value = a[i];
        node->next = NULL;
        if(head == NULL) head = node;
        if(last) last->next = node;
        last = tail = node;
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
        struct Node *node1 = (Node*)malloc(sizeof(Node));
        struct Node *node2 = (Node*)malloc(sizeof(Node));
        int v1 = head->value, v2 = head->next->value;
        while(1LL*i == queries[index_query].round - 1) // caution! round-1!
        {
            queries[index_query].ans1 = head->value;
            queries[index_query].ans2 = head->next->value;
            index_query++;
        }
        if(v1 < v2) swap(v1, v2);
        node1->value = v1;
        if(head->next->next) // caution! special judge!
            node1->next = head->next->next;
        else
            node1->next = node2;
        node2->value = v2;
        node2->next = NULL;
        tail->next = node2;
        tail = node2;
        free(head->next);
        free(head);
        head = node1;
    }
    struct Node *node = head;
    for(int i = 0;i < n;i++)
    {
        b[i] = node->value;
        node = node->next;
    }
    while(index_query < q)
    {
        long long temp_round = queries[index_query].round - maxv; // caution! -maxv!
        queries[index_query].ans1 = b[0];
        queries[index_query].ans2 = b[int((temp_round-1)%(n-1)+1)]; // caution! LL -> int!
        index_query++;
    }
    sort(queries, queries + q, cmp_by_index);
    for(int i = 0;i < q;i++)
        printf("%d %d\n", queries[i].ans1, queries[i].ans2);
    return 0;
}
