#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e6+7;
int l, r[maxn];
char str[maxn];
struct cp{
	double real, imag;
	cp(double real = 0, double imag = 0):real(real), imag(imag){}
	cp operator + (const cp& rhs) const{return cp(real + rhs.real, imag + rhs.imag);}
	cp operator - (const cp& rhs) const{return cp(real - rhs.real, imag - rhs.imag);}
	cp operator * (const cp& rhs) const{return cp(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);}
}text[3][maxn], pattern[3][maxn], ans[3][maxn];
cp omega(int limits, int k)
{
	return cp(cos(PI * k / limits), sin(PI * k / limits));
}
void fft(cp *a, int limits, int inv)
{
	for(int i = 0;i < limits;i++)
		if(i < r[i]) swap(a[i], a[r[i]]);
	for(int mid = 1;mid < limits;mid <<= 1)
	for(int R = mid << 1, j = 0;j < limits;j += R)
		for(int k = 0;k < mid;k++)
		{
			cp w = omega(mid, inv * k) * a[j + k + mid];
			a[j + k + mid] = a[j + k] - w;
			a[j + k] = a[j + k] + w;
		}
	if(inv == -1)
		for(int i = 0;i < limits;i++)
			a[i].real /= limits;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for(int i = 0;i < n;i++)
	{
		if(str[i] == 'R') text[0][n-1-i].real = 1;
		if(str[i] == 'S') text[1][n-1-i].real = 1;
		if(str[i] == 'P') text[2][n-1-i].real = 1;
	}
	scanf("%s", str);
	for(int i = 0;i < m;i++)
	{
		if(str[i] == 'P') pattern[0][i].real = 1;
		if(str[i] == 'R') pattern[1][i].real = 1;
		if(str[i] == 'S') pattern[2][i].real = 1;
	}
	int limits = 1;
	while(limits < n) limits <<= 1, l++;
	for(int i = 0;i < limits;i++)
		r[i] = (r[i>>1]>>1) | ((i&1)<<(l-1));
	for(int _ = 0;_ < 3;_++)
	{
		fft(text[_], limits, 1);
		fft(pattern[_], limits, 1);
		for(int i = 0;i <= limits;i++)
			ans[_][i] = text[_][i] * pattern[_][i];
		fft(ans[_], limits, -1);
	}
	int res = 0;
	for(int i = 0;i < n;i++) // not n+m, but n
		res = max(res, (int)(ans[0][i].real + ans[1][i].real + ans[2][i].real + 0.5));
	printf("%d", res);
	return 0;
}
/*
12 4 RSPPSSSRRPPR RRRR

12 3 RRRRRRRRRRRR SSS

12 4 PPPRRRRRRRRR RSSS

12 4 RRRRRRRRRSSS RRRS
*/