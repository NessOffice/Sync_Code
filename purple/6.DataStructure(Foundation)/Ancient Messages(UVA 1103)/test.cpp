#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const char symbol[8] = {'W', 'A', 'K', 'J', 'S', 'D'};
const char* Hex[] = {"0000", "0001", "0010", "0011",
					 "0100", "0101", "0110", "0111",
					 "1000", "1001", "1010", "1011",
					 "1100", "1101", "1110", "1111"};
int pixel[400 + 5][200 + 5], cnt, n, m, hole;
map<char, int> key;
bool isIn(int r, int c)
{
	if(r < 0 || r > n + 1 || c < 0 || c > m + 1) return false;
	return true;
}
void blankDFS(int r, int c)
{
	if(!isIn(r, c) || pixel[r][c] != '0') return;
	pixel[r][c] = '-';
	blankDFS(r - 1, c);
	blankDFS(r, c - 1);
	blankDFS(r + 1, c);
	blankDFS(r, c + 1);
}
void pixelDFS(int r, int c)
{
	if(!isIn(r, c) || pixel[r][c] != '1') return;
	pixel[r][c] = '-';
	if(pixel[r-1][c] == '0')
		++hole, blankDFS(r-1,c);
	if(pixel[r][c-1] == '0')
		++hole, blankDFS(r,c-1);
	if(pixel[r+1][c] == '0')
		++hole, blankDFS(r+1,c);
	if(pixel[r][c+1] == '0')
		++hole, blankDFS(r,c+1);
	pixelDFS(r - 1, c);
	pixelDFS(r, c - 1);
	pixelDFS(r + 1, c);
	pixelDFS(r, c + 1);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase = 0;
	while(scanf("%d%d", &n, &m) && n)
	{
		memset(pixel, 0, sizeof(pixel)), key.clear(), cnt = 0;
		char temp[100 + 5];
		for(int i = 1;i <= n;i++)
		{
			scanf("%s", temp);
			for(int j = 0;j < m;j++)
				for(int k = 1;k <= 4;k++)
				{
					int ten = temp[j];
					if(ten >= 'a') ten = (ten - 'a' + 10);
					else ten -= '0';
					pixel[i][4 * j + k] = Hex[ten][k-1];
				}
		}
		m *= 4;
		for(int i = 0;i <= n;i++) pixel[i][0] = pixel[i][m + 1] = '0';
		for(int j = 0;j <= m;j++) pixel[0][j] = pixel[n + 1][j] = '0';
		blankDFS(0, 0);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				hole = 0;
				if(pixel[i][j] == '1')
					pixelDFS(i, j), key[symbol[hole]]++;
			}
		printf("Case %d: ", ++kase);
		map<char, int>::iterator it = key.begin();
		while(it != key.end())
		{
			while(it->second--)
				printf("%c", it->first);
			it++;
		}
		printf("\n");
	}
	return 0;
}
