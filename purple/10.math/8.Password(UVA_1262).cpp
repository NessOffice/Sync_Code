#include <cstdio>
#define COL 5
#define ROW 6
char rows[2][8][8], cols[2][8][8], dict[8][8];
int dict_len[8], f[8], a , T;
int calc(int d)
{
    if(d == COL-1) return f[d] = dict_len[d];
    return f[d] = dict_len[d] * calc(d+1);
}
void bubble()
{
    for(int t = 0;t < 2;t++)
        for(int k = 0;k < COL;k++)
        for(int i = 0;i < ROW;i++)
        for(int j = 1;j < ROW-i;j++)
            if(cols[t][k][j-1] > cols[t][k][j])
            {
                char temp = cols[t][k][j-1];
                cols[t][k][j-1] = cols[t][k][j];
                cols[t][k][j] = temp;
            }
}
void dfs(int a, int d)
{
    if(d == COL-1){putchar(dict[d][a]);return;}
    int temp = a / f[d];
    putchar(dict[d][temp]);
    dfs(a-temp*f[d], d+1);
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &a);
        for(int i = 0;i < 2;i++)
        {
            for(int j = 0;j < ROW;j++)
            {
                scanf("%s", rows[i][j]);
                for(int k = 0;k < COL;k++)
                    cols[i][k][j] = rows[i][j][k];
            }
        }
        bubble();
        // for(int k = 0;k < COL;k++)
            // printf("%s\n%s\n", cols[0][k], cols[1][k]);
        for(int k = 0;k < COL;k++)
        {
            int p, len;
            p = len = 0;
            for(int j = 0;j < ROW && p < ROW;j++)
            {
                if(j && cols[0][k][j] == cols[0][k][j-1]) continue;
                while(p < ROW && cols[1][k][p] < cols[0][k][j]) p++;
                if(p >= ROW) break;
                if(cols[1][k][p] == cols[0][k][j])
                    dict[k][len++] = cols[0][k][j];
            }
            dict[k][len] = '\0';
            dict_len[k] = len;
            printf("%s\n", dict[k]);
        }
        calc(0);
        if(a > f[0]) printf("NO\n");
        else{dfs(a, 0);printf("\n");}
    }
    return 0;
}
