#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 3e5+5; // caution!!!
int mark_vertex[maxn], ans_edge[2*maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m, cnt = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= 3*n;i++)
            mark_vertex[i] = 0;
        for(int i = 1;i <= m;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(mark_vertex[u] == 0 && mark_vertex[v] == 0)
            {
                ans_edge[++cnt] = i;
                mark_vertex[u] = mark_vertex[v] = 1;
            }
        }
        if(cnt >= n){
            printf("Matching\n");
            for(int i = 1;i <= n;i++)
                printf("%d ", ans_edge[i]);
            putchar('\n');
        }else{
            printf("IndSet\n");
            int cnt_of_vertex = 0;
            for(int i = 1;i <= 3*n && cnt_of_vertex < n;i++)
                if(mark_vertex[i] == 0)
                {
                    printf("%d ", i);
                    cnt_of_vertex++;
                }
            putchar('\n');
        }
    }
    return 0;
}
/*
4

1 2
1 3
1 2

1 2
1 3
1 2

2 5
1 2
3 1
1 4
5 1
1 6

2 15
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6

*/