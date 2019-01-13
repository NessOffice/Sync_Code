#include <cstdio>
#include <cstring>
const int maxn = 10 + 2;
int n, m, cnt;
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
bool dfs(int d, int maxd, int cnt2)
{
	// if(cnt2 == 0) return true;
	if(d == maxd) return check();
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	{
		// if(pos[0][i] || pos[1][j]) continue;
		// if(diag[0][i+j] || diag[1][tr(i,j)]) continue;
		int newcnt = cnt2;
		// for(int i2 = 0;i2 < n;i2++)
		// for(int j2 = 0;j2 < m;j2++)
		// {
			// if(pos[0][i2] || pos[1][j2]) continue;
			// if(diag[0][i2+j2] || diag[1][tr(i2,j2)]) continue;
			// if(board[i2][j2] == 'X')
			// if(i2 == i || j2 == j 
			// || i2 + j2 == i + j 
			// || tr(i2,j2) == tr(i,j))
				// newcnt--;
		// }
		operate(i, j, 1);
		if(dfs(d + 1, maxd, newcnt)){printf("%d %d %d\n", i, j, newcnt);return true;}
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
		cnt = 0;
		for(int i = 0;i < n;i++)
		{
			fgets(board[i], maxn, stdin);
			for(int j = 0;j < m;j++)
				if(board[i][j] == 'X') cnt++;
		}
		for(int maxd = 1;maxd < 10;maxd++)
			if(dfs(0, maxd, cnt))
			{
				printf("case %d:%d\n", ++kase, maxd);
				break;
			}
	}
	return 0;
}
