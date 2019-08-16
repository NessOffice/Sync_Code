#include <cstdio>
#include <cstring>
const int maxn = 1010;
const int maxfibo = 20;
int fibo[maxfibo];
int SG[maxn];
int state[maxn];
void calc_SG(int n, int *stgy, int sz_of_stgy) // stgy for strategy
{
	memset(SG, -1, sizeof(SG));
	SG[0] = 0;
	for(int i = 1;i < n;i++)
	{
		memset(state, 0, sizeof(state));
		for(int j = 1;j < sz_of_stgy && stgy[j] <= i;j++)
			state[SG[i-stgy[j]]] = 1;
		for(int j = 0;SG[i] == -1;j++)
			if(state[j] == 0)
				SG[i] = j;
	}
}
void calc_fibo()
{
	fibo[1] = fibo[2] = 1;
	for(int i = 3;i < maxfibo;i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}
int main()
{
	calc_fibo();
	calc_SG(maxn, fibo, maxfibo);
	int n1, n2, n3;
	while(1)
	{
		scanf("%d%d%d", &n1, &n2, &n3);
		if(n1 + n2 + n3 == 0) break;
		printf("%s\n", (SG[n1]^SG[n2]^SG[n3]) ? "Fibo" : "Nacci");
	}
	return 0;
}
