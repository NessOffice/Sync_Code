#include <stdio.h>
#include <math.h>
int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);
	double ln_n = log10(n), ln_r, r;
	double lnln_n = log10(ln_n), lnln_r;
	lnln_r = k*log10(0.5) + lnln_n;
	ln_r = pow(10, lnln_r), r = pow(10, ln_r);
	printf("%.3lf", r);
	return 0;
}
