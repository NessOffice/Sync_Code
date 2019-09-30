#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 1e7 + 7;
int l, r[MAXN];
struct cp{
	double real, imag;
	cp(double real = 0, double imag = 0):real(real), imag(imag){}
	cp operator + (const cp& rhs) const{return cp(real + rhs.real, imag + rhs.imag);}
	cp operator - (const cp& rhs) const{return cp(real - rhs.real, imag - rhs.imag);}
	cp operator * (const cp& rhs) const{return cp(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);}
}A[MAXN], B[MAXN];
cp omega(int limits, int k)
{
	return cp(cos(PI * k / limits), sin(PI * k / limits));
}
void fft(cp *a, int limits, int type)
{
	for(int i = 0;i < limits;i++)
		if(i < r[i]) swap(a[i], a[r[i]]);
	for(int mid = 1;mid < limits;mid <<= 1)
	for(int R = mid << 1, j = 0;j < limits;j += R)
		for(int k = 0;k < mid;k++)
		{
			cp w = omega(mid, type * k) * a[j + k + mid];
			a[j + k + mid] = a[j + k] - w;
			a[j + k] = a[j + k] + w;
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
	while(limits <= m + n) limits <<= 1, l++;
	for(int i = 0;i < limits;i++)
		r[i] = (r[i>>1]>>1) | ((i&1)<<(l-1));
	fft(A, limits, 1);
	fft(B, limits, 1);
	for(int i = 0;i <= limits;i++)
		A[i] = A[i]*B[i];
	fft(A, limits, -1);
	for(int i = 0;i <= n + m;i++)
		printf("%d ", (int)(A[i].real / limits + 0.5));
	return 0;
}
