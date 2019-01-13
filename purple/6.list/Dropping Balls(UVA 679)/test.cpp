#include <cstdio>
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, D, I;
	while(scanf("%d",&n) && n>=0)
	{
		while(n--)
		{
			scanf("%d%d",&D,&I);
			int k = 1;
			for(int i = 1;i < D;i++)
			{
				if(I%2){k*=2;I=(I+1)/2;}
				else{k=k*2+1;I/=2;}
			}
			printf("%d\n",k);
		}
	}
	return 0;
}
