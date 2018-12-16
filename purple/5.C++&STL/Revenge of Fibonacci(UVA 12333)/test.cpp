#include <cstdio>
#include <cstring>
struct Digit{
	int val;
	Digit* next[10];
	Digit(int _val):val(_val){
		for(int i = 0;i < 10;i++) next[i] = NULL;
	}
};
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int fib[2][30000];
	Digit head = Digit(-1);
	fib[0][0] = fib[1][0] = 1;
	head.next[1] = new Digit(0);
	int begin = 0, end = 1;
	for(int i = 2;i < 100000;i++)
	{
		int pos, p = i&1, q = (i+1)&1;
		Digit* node = &head;
		int carry = 0;
		for(pos = begin;pos < end;pos++)
		{
			fib[p][pos] += fib[q][pos];
			if(carry){fib[p][pos]++;carry=0;}
			if(fib[p][pos] > 9){fib[p][pos]-=10;carry=1;}
		}
		if(carry) fib[p][end++] = 1;
		if(end - begin > 50) begin++;
		for(pos = end - 1;pos >= begin;pos--)
		{
			int r = fib[p][pos];
			if(node->next[r] == NULL) node->next[r] = new Digit(i);
			node = node->next[r];
		}
	}
	int q;scanf("%d", &q);
	for(int i = 1;i <= q;i++)
	{
		printf("Case #%d: ", i);
		char num[50];
		scanf("%s", num);
		int len = strlen(num), pos = 0;
		Digit *node = &head;
		for(;pos < len;pos++)
		{
			int r = num[pos] - '0';
			if(node->next[r] == NULL){printf("-1\n");break;}
			else node = node->next[r];
		}
		if(pos == len) printf("%d\n", node->val);
	}
	return 0;
}
