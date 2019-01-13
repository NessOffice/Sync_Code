#include <cstdio>
const int maxn = 1000;
int cnt, n, L, s[maxn];
bool search(int cur)
{
	if(cur) cnt++;
	if(cnt == n){
		for(int i = 0;i < cur;i++)
		{
			if(i && i % 64 == 0) putchar('\n');
			else if(i && i % 4 == 0) putchar(' ');
			printf("%c", s[i] + 'A');
		}
		printf("\n%d\n", cur);
		return true;
	}else{
		for(int i = 0;i < L;i++)
		{
			s[cur] = i;
			bool flag = true;
			for(int j = 1;2*j <= cur+1 && flag;j++)
			{
				bool equal = cur ? true : false;
				for(int k = 0;k < j && equal;k++)
					if(s[cur-k] != s[cur-j-k]) equal = false;
				if(equal) flag = false;
			}
			if(flag && search(cur+1)) return true;
		}
	}
	return false;
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(scanf("%d%d", &n, &L), n)
		cnt = 0, search(0);
	return 0;
}
