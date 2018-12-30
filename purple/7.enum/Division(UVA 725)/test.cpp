#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n, first = 0, flag;
	char out[20];
	while(scanf("%d", &n), n)
	{
		if(first++) printf("\n");
		flag = 1;
		for(int fghij = 0;;fghij++)
		{
			int abcde = n * fghij;
			sprintf(out, "%05d%05d", abcde, fghij);
			if(strlen(out) > 10) break;
			sort(out, out + 10);
			int i = 0;
			for(;i < 10;i++)
				if(out[i] != i + '0') break;
			if(i == 10)
			{
				printf("%05d / %05d = %d\n", abcde, fghij, n);
				flag = 0;
			}
		}
		if(flag) printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
