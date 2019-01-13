#include <cstdio>
using namespace std;
bool isBalance(int& W)
{
	int W1, D1, W2, D2;
	bool b1 = true, b2 = true;
	scanf("%d%d%d%d", &W1, &D1, &W2, &D2);
	if(!W1) b1 = isBalance(W1);
	if(!W2) b2 = isBalance(W2);
	W = W1 + W2;
	return b1 && b2 && (W1*D1 == W2*D2);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n, W;
	scanf("%d", &n);
	while(n--)
	{
		if(isBalance(W)) printf("YES\n");
		else printf("NO\n");
		if(n) printf("\n");
	}
	return 0;
}
