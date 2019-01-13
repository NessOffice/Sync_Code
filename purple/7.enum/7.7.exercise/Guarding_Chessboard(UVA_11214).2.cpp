#include <cstdio>
#include <cstring>
const int maxn = 10 + 2;
int n, m, cnt, maxd;
char board[maxn][maxn];
int diag[2][2*maxn];
//第一个参数 0 表示相加，1 表示相减
int pos[2][maxn];
//第一个参数 0 表示行，1 表示列
int tr(int i, int j){return i - j + maxn;}
bool check()
{
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	if(board[i][j] == 'X')
	if(!pos[0][i] && !pos[1][j] && !diag[0][i+j] && !diag[1][tr(i,j)])
		return false;
	return true;
}
void operate(int i, int j, int value)
{
	diag[0][i+j] = value;
	diag[1][tr(i,j)] = value;
	pos[0][i] = value;
	pos[1][j] = value;
}
bool dfs(int d, int r)
{
	if(d == maxd) return check();
	for(int i = r;i < n;i++)
	for(int j = 0;j < m;j++)
	{
		operate(i, j, 1);
		if(dfs(d + 1, r + 1)){printf("%d %d\n", i, j);return true;}
		operate(i, j, 0);
	}
	return false;
}
int main()
{
	int kase = 0;
	while(scanf("%d%d\n", &n, &m), n)
	{
		memset(diag, 0, sizeof(diag));
		memset(pos, 0, sizeof(pos));
		for(int i = 0;i < n;i++)
			fgets(board[i], maxn, stdin);
		for(maxd = 1;maxd < 5;maxd++)
			if(dfs(0, 0)) break;
		printf("case %d:%d\n", ++kase, maxd);		
	}
	return 0;
}
