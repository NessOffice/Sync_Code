#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 75 + 5, R = 20 + 4, C = 10 + 2;
int vis[R][C];
bool ok;
struct Cell{
	int val, remain;
	char context[maxn];
	vector<int> r_set;
	vector<int> c_set;
	vector<int> flags;
}cells[R][C];
int calDFS(int r, int c, bool &check)
{
	if(vis[r][c] == -1|| cells[r][c].remain == -1)
		check = false;
	vis[r][c] = -1;
	int ans = cells[r][c].val, len = cells[r][c].remain;
	for(int i = 0;i < len && check;i++)
		ans += cells[r][c].flags[i] * calDFS(cells[r][c].r_set[i], cells[r][c].c_set[i], check);
	if(!check)
	{
		cells[r][c].remain = -1, ok = false;
		return ans;
	}
	vis[r][c] = 1;
	if(cells[r][c].remain > 0) cells[r][c].remain = 0;
	return cells[r][c].val = ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int row, col;
	bool check;
	char str[maxn];
	while(~scanf("%d%d", &row, &col) && row)
	{
		memset(vis, 0, sizeof(vis)), ok = true;
		for(int r = 0;r < row;r++)
		for(int c = 0;c < col;c++)
		{
			cells[r][c].r_set.clear();
			cells[r][c].c_set.clear();
			cells[r][c].flags.clear();
			scanf("%s", str);
			strcpy(cells[r][c].context, str);
			cells[r][c].val = cells[r][c].remain = 0;
			int flag = 1, index = 0, len = strlen(str), temp;
			while(index < len)
			{
				temp = 0;
				if(isalpha(str[index]))
				{
					cells[r][c].remain++;
					cells[r][c].r_set.push_back(str[index++] - 'A');
					cells[r][c].c_set.push_back(str[index++] - '0');
					cells[r][c].flags.push_back(flag);
				}
				if(str[index] == '+') flag = 1, index++;
				if(str[index] == '-') flag = -1, index++;
				while(isdigit(str[index]) && index < len)
					temp *= 10, temp += str[index] - '0', index++;
				cells[r][c].val += flag * temp;
			}
		}
		for(int r = 0;r < row;r++)
		for(int c = 0;c < col;c++)
			calDFS(r, c, check = true);
		if(ok){
			putchar(' ');
			for(int c = 0; c < col; c++) printf("%6d", c);
			printf("\n");
			for(int r = 0; r < row; r++)
			{
				putchar(r + 'A');
				for(int c = 0; c < col; c++)
					printf("%6d",cells[r][c].val);
				printf("\n");
			}
		}else{
			for(int r = 0;r < row;r++)
			for(int c = 0;c < col;c++)
				if(cells[r][c].remain == -1)
					printf("%c%c: %s\n", r + 'A', c + '0', cells[r][c].context);
		}
		printf("\n");
	}
	return 0;
}
