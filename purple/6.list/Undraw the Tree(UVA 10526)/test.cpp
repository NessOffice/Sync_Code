#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn = 200 + 10;
char buf[maxn][maxn];
int n;
void undrawDFS(int r, int c)
{
	printf("%c(", buf[r][c]);
	if(r + 1 < n && buf[r+1][c] == '|')
	{
		int i = c;
		while(i > 0 && buf[r+2][i-1] == '-') i--;
		while(buf[r+2][i] == '-' && buf[r+3][i] != '\0')
		{
			if(!isspace(buf[r+3][i]))
				undrawDFS(r+3, i);
			i++;
		}
	}
	printf(")");
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &T);
	while(T--)
	{
		n = 0;
		while(++n)
		{
			fgets(buf[n], maxn, stdin);
			if(buf[n][0] == '#') break;
		}
		printf("(");
		int len = strlen(buf[1]);
		for(int i = 0;n > 1 && i < len;i++)
			if(!isspace(buf[1][i]))
				undrawDFS(1, i);
		printf(")\n");
	}
	return 0;
}
