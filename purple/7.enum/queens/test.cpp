#include <cstdio>
#include <ctime>
int vis[3][30] = {0}, tot = 0, n;
//n = 13 与 n = 14之间，时间从 0.00 跳到了 2.00！
void search(int cur)
{
	if(cur == n){tot++;return;}
	for(int i = 0;i < n;i++)
	if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
	{
		vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
		search(cur+1);
		vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
	}
}
int main()
{
	n = 13, search(0);
	printf("%d, Time used = %.2lf", tot, double(clock() / CLOCKS_PER_SEC));
	return 0;
}