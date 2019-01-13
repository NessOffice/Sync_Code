#include <cstdio>
#include <cstdlib>
#include <ctime> 
void random_generator(int cnt){
	for(int i=0;i<cnt;i++)
	{
		int n = 1.0*rand()/RAND_MAX*1 + 1;
		printf("%d\n",n);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<3;k++)
			{
				int x = 1.0*rand()/RAND_MAX*256;
				printf("%d.",x);
			}
			int x = 1.0*rand()/RAND_MAX*256;
			printf("%d\n",x);
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	random_generator(1000000);
	return 0;
} 
