#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Stu{
    char name[20];
    int sub[1010];
    int ok;
}stu[1010];
bool cmp(int A, int j, int r, int type)
{
    if(!type && stu[A].sub[r] != stu[j].sub[r]) return stu[A].sub[r] < stu[j].sub[r];
    if(!type && stu[A].sub[r] == stu[j].sub[r]) return strcmp(stu[j].name, stu[A].name) > 0;
    if(type && stu[A].sub[r] != stu[j].sub[r]) return stu[A].sub[r] > stu[j].sub[r];
    if(type && stu[A].sub[r] == stu[j].sub[r]) return strcmp(stu[j].name, stu[A].name) < 0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
        {
            scanf("%s", stu[i].name);
            stu[i].ok = 0;
            for(int j = 0;j < m;j++)
                scanf("%d", &stu[i].sub[j]);
        }
        for(int i = 0;i < n/2;i++)
        {
            int r = i%m, A = -1, B = -1;
            for(int j = 0;j < n;j++)
            {
                if(!stu[j].ok && (A<0 || cmp(A, j, r, 0))) A = j;
                if(!stu[j].ok && (B<0 || cmp(B, j, r, 1))) B = j;
            }
            printf("%s %s\n", stu[A].name, stu[B].name);
            stu[A].ok = stu[B].ok = 1;
        }
    }
    return 0;
}