#include <cstdio>
#include <cstring>
const int maxn = 10 + 2;
int n, m, cnt;
char board[maxn][maxn];
int diag[2][2][2*maxn];
//第一个参数 0 表示守卫，1 表示皇后
//第二个参数 0 表示相加，1 表示相减
int pos[2][2][maxn];
//第二个参数 0 表示行，1 表示列
int tr(int i, int j){return i - j + maxn;}
void operate(int i, int j, int type, int value)
{
	diag[type][0][i+j] = value;
	diag[type][0][tr(i,j)] = value;
	pos[type][0][i] = value;
	pos[type][1][j] = value;
}
bool dfs(int d, int maxd, int cnt2)
{
	if(cnt2 == 0) return true;
	if(d == maxd) return false;
	for(int i = 0;i < n;i++)
	for(int j = 0;j < m;j++)
	{
		if(pos[1][0][i] || pos[1][1][j]) continue;
		if(diag[1][0][i+j] || diag[1][1][tr(i,j)]) continue;
		if(!pos[0][0][i] && !pos[0][1][j]) continue;
		if(!diag[0][0][i+j] && !diag[0][1][tr(i,j)]) continue;
		int newcnt = cnt2;
		for(int i2 = 0;i2 < n;i2++)
		for(int j2 = 0;j2 < m;j2++)
		if(board[i2][j2] == 'X')
		{
			if(i2 == i && !pos[1][0][i]) newcnt--;
			else if(j2 == j && !pos[1][0][j]) newcnt--;
			else if(i2 + j2 == i + j && !diag[1][0][i+j]) newcnt--;
			else if(tr(i2,j2) == tr(i,j) && !diag[1][1][tr(i,j)]) newcnt--;
			printf("%d\n", newcnt);
		}
			// if(pos[1][0][i2] && pos[0][0][i2]) newcnt--;
			// else if(pos[1][1][j2] && pos[0][1][j2]) newcnt--;
			// else if(diag[1][0][i2+j2] && diag[0][0][i2+j2]) newcnt--;
			// else if(diag[1][1][abs(i2-j2)] && diag[0][1][abs(i2-j2)]) newcnt--;
		operate(i, j, 1, 1);
		
		if(dfs(d + 1, maxd, newcnt)) return true;
		operate(i, j, 1, 0);
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
				if(board[i][j] == 'X')
					operate(i, j, 0, 1), cnt++;
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
