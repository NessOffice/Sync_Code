#include <cstdio>
#include <cmath>
const double PI = acos(-1.0);
const int MAXN = 1e7 + 7;
struct cp{
	double real, imag;
	cp(double real = 0, double imag = 0):real(real), imag(imag){}
	cp operator + (const cp& rhs) const{return cp(real + rhs.real, imag + rhs.imag);}
	cp operator - (const cp& rhs) const{return cp(real - rhs.real, imag - rhs.imag);}
	cp operator * (const cp& rhs) const{return cp(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);}
}A[MAXN], B[MAXN];
cp omega(int limits, int k)
{
	return cp(cos(2.0 * PI * k / limits), sin(2.0 * PI * k / limits));
}
void fft(cp *a, int limits, int type)
{
	if(limits == 1) return;
	cp a1[limits>>1], a2[limits>>1];
	int m = limits / 2;
	for(int i = 0;i <= limits;i += 2)
	{
		a1[i>>1] = a[i];
		a2[i>>1] = a[i+1];
	}
	fft(a1, m, type);
	fft(a2, m, type);
	for(int i = 0;i < m;i++)
	{
		cp w = omega(limits, type * i);
		a[i] = a1[i] + w * a2[i];
		a[i + m] = a1[i] - w * a2[i];
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0;i <= n;i++)
		scanf("%lf", &A[i].real);
	for(int j = 0;j <= m;j++)
		scanf("%lf", &B[j].real);
	int limits = 1;
	while(limits <= m + n) limits <<= 1;
	fft(A, limits, 1);
	fft(B, limits, 1);
	for(int i = 0;i <= limits;i++)
		A[i] = A[i]*B[i];
	fft(A, limits, -1);
	for(int i = 0;i <= n + m;i++)
		printf("%d ", (int)(A[i].real / limits + 0.5));
	return 0;
}
