#include <cstdio>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int r, c;
        scanf("%d%d", &r, &c);
        if((r & 1) && (c & 1))
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}