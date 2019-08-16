#include <stdio.h>
long long euclid(long long a, long long b)
{
	if(a < b) return euclid(b, a);
	return b == 0 ? a : euclid(b, a % b);
}
long long abs(long long a)
{
	return a > 0 ? a : -a;
}
int main()
{
    char temp[100];
	long long i, j, n, a, b, f, son = 0, mom = 1, d;
	scanf("%lld", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%s", temp);
		sscanf(temp, "%lld/%lld", &a, &b);
		// the code below is also beautiful
		
		// f = a = b = 0;
		// if(temp[0] == '-') f = 1;
		// for(j = f;temp[j] != '/';j++)
		// {
		// 	a *= 10;
		// 	a += temp[j]-'0';
		// }
		// for(j++;temp[j];j++)
		// {
		// 	b *= 10;
		// 	b += temp[j]-'0';
		// }
		// if(f) a = -a;
		son = son*b + mom*a;
		mom *= b;
		d = euclid(abs(son), mom);
		son /= d;
		mom /= d;
	}
	mom *= n;
	d = euclid(abs(son), mom);
	son /= d;
	mom /= d;
	printf("%lld", son);
	if(mom > 1) printf("/%lld", mom);
    return 0;
}
