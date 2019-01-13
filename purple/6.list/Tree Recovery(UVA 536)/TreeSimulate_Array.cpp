#include <cstdio>
#include <cstring>
const int maxn = 26 + 4;
char preOrder[maxn], inOrder[maxn];
void postOrder(int L1, int R1, int L2, int R2)
{
	if(L1 >= R1) return;
	int root = preOrder[L1], cnt = 0;
	while(inOrder[L2 + cnt] != root) cnt++;
	postOrder(L1 + 1, L1 + cnt + 1, L2, L2 + cnt);
	postOrder(L1 + cnt + 1, R1, L2 + cnt + 1, R2);
	printf("%c", root);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s", preOrder) == 1)
	{
		scanf("%s", inOrder);
		int len = strlen(preOrder);
		postOrder(0, len, 0, len);
		printf("\n");
	}
	return 0;
}
