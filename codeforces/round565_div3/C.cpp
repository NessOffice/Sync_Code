#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 5;
int rmap[50];
int groups[maxn], index_num2group[6];
void init()
{
    rmap[4] = 0;
    rmap[8] = 1;
    rmap[15] = 2;
    rmap[16] = 3;
    rmap[23] = 4;
    rmap[42] = 5;
    memset(groups, 0, sizeof(groups));
    memset(index_num2group, 0, sizeof(index_num2group));
}
int main()
{
    init();
    int n, num_of_groups = 0;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        int temp, index_of_num, index_of_group;
        scanf("%d", &temp);
        index_of_num = rmap[temp];
        index_of_group = index_num2group[index_of_num];
        if(groups[index_of_group] == index_of_num)
        // check the order of the new element(avoid operations like 4, 8 -> 4, 8, 16)
        {
            groups[index_of_group]++;
            index_num2group[index_of_num]++;
            if(index_of_num == 5)
                num_of_groups++;
        }
    }
    printf("%d\n", n - 6*(num_of_groups));
    return 0;
}