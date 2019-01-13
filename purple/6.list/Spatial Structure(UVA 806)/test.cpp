#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 
const int len = (1<<6) + 2;
int cnt, tree[len * len];
char pixel[len][len];
void treeTransfer(int r, int c, int width, int value)
{
	bool black = true, white = true;
	for(int i = r;i < r + width;i++)
	for(int j = c;j < c + width;j++)
	{
		if(pixel[i][j] == '0') black = false;
		if(pixel[i][j] == '1') white = false;
	}
	if(black){
		tree[cnt++] = value;
	}else if(!white){
		int pos = 1;
		while(pos <= value) pos *= 5;
		treeTransfer(r, c, width / 2, value + pos);
		treeTransfer(r, c + width / 2, width / 2, value + 2 * pos);
		treeTransfer(r + width / 2, c, width / 2, value + 3 * pos);
		treeTransfer(r + width / 2, c + width / 2, width / 2, value + 4 * pos);
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n, kase = 0;
	while(scanf("%d", &n), n)
	{
		memset(pixel, 0, sizeof(pixel)), cnt = 0;
		if(kase++) printf("\n");
		printf("Image %d", kase);
		if(n > 0){
			for(int i = 0;i < n;i++)
				scanf("%s", pixel[i]);
			treeTransfer(0, 0, n, 0);
			sort(tree, tree + cnt);
			int i = 0;
			for(;i < cnt;i++)
			{
				if(i % 12 == 0) printf("\n");
				if(i % 12 != 0) printf(" ");
				printf("%d", tree[i]);
			}
			printf("\n");
			printf("Total number of black nodes = %d\n", cnt);
		}else{
			for(int i = 0;i < -n;i++)
			for(int j = 0;j < -n;j++)
				pixel[i][j] = '.';
			int value;
			while(scanf("%d", &value) && value != -1)
			{
				int r = 0, c = 0, width = -n;
				while(value)
				{
					int pos = value % 5;
					width /= 2;
					if(pos == 2 || pos == 4) c += width;
					if(pos == 3 || pos == 4) r += width;
					value /= 5;
				}
				for(int i = r;i < r + width;i++)
				for(int j = c;j < c + width;j++)
					pixel[i][j] = '*';
			}
			printf("\n");
			for(int i = 0;i < -n;i++)
				printf("%s\n", pixel[i]);
		}
	}
	printf("%d",len);
	return 0;
}
