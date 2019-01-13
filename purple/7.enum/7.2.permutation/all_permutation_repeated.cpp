#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
void next_permutation(int n, int* P, int* A, int cur)
{
	if(cur == n){
		for(int i = 0;i < n;i++)
			printf("%d ", A[i]);
		printf("\n");
	}else for(int i = 0;i < n;i++)
		if(!i || P[i] != P[i-1]){
			int cnt_1 = 0, cnt_2 = 0;
			for(int j = 0;j < cur;j++)
				if(A[j] == P[i]) cnt_1++;
			for(int j = 0;j < n;j++)
				if(P[j] == P[i]) cnt_2++;
			if(cnt_1 < cnt_2)
			{
				A[cur] = P[i];
				next_permutation(n, P, A, cur+1);
			}
		}
}
int main()
{
	freopen("out.txt","w",stdout);
	int n = 9, P[] = {1,1,1,3,2,4,5,6,7}, A[12];
	std::sort(P, P + n);
	next_permutation(n, P, A, 0);
	printf("%.3lf", double(clock()) / CLOCKS_PER_SEC);
	return 0;
}
