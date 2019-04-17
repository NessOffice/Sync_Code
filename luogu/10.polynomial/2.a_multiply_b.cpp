#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = 300020;
char num[MAXN];
int l, r[MAXN];
int ans[MAXN];
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
	int n;
	scanf("%d", &n);
	n--;
	scanf("%s", num);
	for(int i = n;i >= 0;i--)
		A[n-i].real = num[i]-'0';
	scanf("%s", num);
	for(int i = n;i >= 0;i--)
		B[n-i].real = num[i]-'0';
	n *= 2;
	int limits = 1;
	while(limits <= n) limits <<= 1, l++;
	for(int i = 0;i < limits;i++)
		r[i] = (r[i>>1]>>1) | ((i&1)<<(l-1));
	fft(A, limits, 1);
	fft(B, limits, 1);
	for(int i = 0;i <= limits;i++)
		A[i] = A[i]*B[i];
	fft(A, limits, -1);
	memset(ans, 0, sizeof(ans));
	for(int i = 0;i <= n+2;i++)
	{
		ans[i] += (int)(A[i].real / limits + 0.5);
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
	int first = 0;
	for(int i = n+2;i >= 0;i--)
	{
		if(ans[i]) first++;
		if(!first && !ans[i]) continue;
		printf("%d", ans[i]);
	}
	return 0;
}
