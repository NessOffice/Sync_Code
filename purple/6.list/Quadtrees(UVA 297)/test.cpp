#include <cstdio>
#include <cstring>
const int maxn = 1024 + 10, len = 32;
char tree[maxn];
int pixel[len][len], cnt;
void drawTree(int& p, int r, int c, int w)
{
	char ch = tree[p++];
	if(ch == 'p'){
		drawTree(p, r, c + w / 2, w / 2);
		drawTree(p, r, c, w / 2);
		drawTree(p, r + w / 2, c, w / 2);
		drawTree(p, r + w / 2, c + w / 2, w / 2);
	}else if(ch == 'f'){
		for(int i = r;i < r + w;i++)
		for(int j = c;j < c + w;j++)
			if(pixel[i][j] == 0){pixel[i][j] = 1;cnt++;}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n, p;scanf("%d", &n);
	while(n--)
	{
		memset(pixel, 0, sizeof(pixel)), cnt = 0;
		p = 0;scanf("%s", tree);drawTree(p, 0, 0, len);
		p = 0;scanf("%s", tree);drawTree(p, 0, 0, len);
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}
