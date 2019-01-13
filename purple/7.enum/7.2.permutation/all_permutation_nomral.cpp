#include <cstdio>
#include <cstring>
#include <ctime>
//the efficience:
//n = 9 : 10sec
//n = 8 : 1sec
//n = 7 : 0.1sec
//n = 6 : 0.016sec
void next_permutation(int n, int* A, int cur)
{
	if(cur > n){
		for(int i = 1;i <= n;i++)
			printf("%d ", A[i]);
		printf("\n");
	}else for(int i = 1;i <= n;i++){
			bool flag = true;
			for(int j = 1;j < cur;j++)
				if(A[j] == i) flag = false;
			if(flag)
			{
				A[cur] = i;
				next_permutation(n, A, cur+1);
			}
		}
}
int main()
{
	// freopen("out.txt","w",stdout);
	int n = 6, A[12];
	for(int i = 1;i <= n;i++) A[i] = i;
	next_permutation(n, A, 1);
	printf("Time used: %.3lf", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
