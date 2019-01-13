#include <cstdio>

/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

int line[8][7] = {
	{ 0, 2, 6,11,15,20,22},
	{ 1, 3, 8,12,17,21,23},
	{10, 9, 8, 7, 6, 5, 4},
	{19,18,17,16,15,14,13},
};
const int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};
const int center[8] = {6, 7, 8, 11, 12 ,15, 16, 17};
int block[24];
char ans[1000];
int h()
{
	int mis, ans = 1000;
	for(int i = 1;i <= 3;i++)
	{
		mis = 0;
		for(int j = 0;j < 8;j++)
			if(block[center[j]] != i) mis++;
		if(mis < ans) ans = mis;
	}
	return ans;
}
void move(int i)
{
	int tmp = block[line[i][0]];
	for(int j = 0;j < 6;j++)
		block[line[i][j]] = block[line[i][j+1]];
	block[line[i][6]] = tmp;
}
bool dfs(int d, int maxd)
{
	if(h() == 0){ans[d] = '\0';printf("%s\n", ans);return true;}
	if(d + h() > maxd) return false;
	for(int i = 0;i < 8;i++)
	{
		ans[d] = 'A' + i;
		move(i);
		if(dfs(d + 1, maxd)) return true;
		move(rev[i]);
	}
	return false;
}
int main()
{
	for(int i = 4;i < 8;i++)
	for(int j = 0;j < 7;j++)
		line[i][j] = line[rev[i]][6-j];
	while(scanf("%d", &block[0]), block[0])
	{
		for(int i = 1;i < 24;i++) scanf("%d", &block[i]);
		if(h() == 0){
			printf("No moves needed\n");
		}else{
			for(int maxd = 1;;maxd++)
				if(dfs(0, maxd)) break;
		}
		printf("%d\n", block[center[0]]);
	}
	return 0;
}
