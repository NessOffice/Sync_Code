#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 1e5 + 10;
const double PI = acos(-1.0);
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
		if(i < r[i]){cp t = a[i];a[i] = a[r[i]];a[r[i]] = t;}
	for(int mid = 1;mid < limits;mid <<= 1)
	for(int R = mid << 1, j = 0;j < limits;j += R)
		for(int k = 0;k < mid;k++)
		{
			cp w = omega(mid, type * k) * a[j + k + mid];
			a[j + k + mid] = a[j + k] - w;
			a[j + k] = a[j + k] + w;
		}
}
struct BN
{
	char num[MAXN];// the digits are stored reversely
	int len;
}n, ans, CONST_1;
void swap2(char *a,char *b){char t=*a;*a=*b;*b=t;}
void BNInit(struct BN *a, int b)
{
	a->len = 0;
	while(b)
	{
		a->num[a->len] = b % 10;
		b /= 10;
		a->len++;
	}
}

void BNScanf(struct BN *ans)
{
	int i, len;
	char str[MAXN];
	scanf("%s", str);
    len = strlen(str);
	for(i = 0;i < len;i++)
		ans->num[i] = str[len-1-i] - '0';
	ans->len = len;
}
void BNPrint(struct BN a)
{
	if(a.len == 0) putchar('0');
	for(int i = a.len-1;i >= 0;i--)
		putchar(a.num[i] + '0');
	putchar('\n');
}
void BNAdd(struct BN a,struct BN b,struct BN *c)
{
	int i;
	c->len = (a.len > b.len ? a.len : b.len);
	for(i = a.len;i <= c->len;i++) a.num[i] = 0;
	for(i = b.len;i <= c->len;i++) b.num[i] = 0;
	int carry = 0;
	for(i = 0;i < c->len;i++)
	{
		c->num[i] = a.num[i]+b.num[i];
		if(carry){c->num[i]++;carry=0;}
		if(c->num[i] > 9){c->num[i] -= 10;carry = 1;}
	}
	if(carry){c->num[c->len++]=1;c->num[c->len]='\0';}
}
void BNMultiply(struct BN a,struct BN b,struct BN *c)
{
	for(int i = a.len;i >= 0;i--)
		A[i].real = a.num[i];
	for(int j = b.len;j >= 0;j--)
		B[j].real = b.num[j];
	int limits = 1;
	while(limits <= a.len + b.len) limits <<= 1, l++;
	for(int i = 0;i < limits;i++)
		r[i] = (r[i>>1]>>1) | ((i&1)<<(l-1));
	fft(A, limits, 1);
	fft(B, limits, 1);
	for(int i = 0;i <= limits;i++)
		A[i] = A[i]*B[i];
	fft(A, limits, -1);
	for(int i = 0;i <= a.len + b.len;i++)
		c->num[i] = (int)(A[i].real / limits + 0.5);
    c->len = a.len + b.len + 1;
}
void BNDiv(struct BN a, int b, struct BN *c, int *r)
{
	for(int i = 0;i < a.len/2;i++)
		swap2(a.num+i,a.num+a.len-1-i);
	*r = 0;
	BNInit(c, 0);
    for(int i = 0;i < a.len;i++)
    {
        (*r) = (*r)*10 + a.num[i];
        if(c->len|| (*r) >= b)
        {
            c->num[c->len] = (*r) / b;
            (*r) %= b;
            c->len++;
        }
    }
    for(int i = 0;i < c->len/2;i++)
		swap2(c->num+i,c->num+c->len-1-i);
}
int main()
{
    int r;
    BNScanf(&n);
    BNInit(&ans, 1);
    BNInit(&CONST_1, 1);
    for(int i = 0;i < 4;i++)
    {
        BNAdd(n, CONST_1, &n);
        BNMultiply(n, ans, &ans);
    }
    BNDiv(ans, 24, &ans, &r);
    BNPrint(ans);
    return 0;
}
