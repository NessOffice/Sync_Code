#include <stdio.h>
#include <string.h>
#define MAXN 1200
struct BN
{
	char num[MAXN];// the digits are stored reversely
	int len;
};
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
// lhs > rhs : return 1
// lhs == rhs : return 0
// lhs < rhs : return -1
int BNCmp(struct BN *lhs, struct BN *rhs)
{
	int i;
	if(lhs->len != rhs->len)
		return lhs->len > rhs->len ? 1 : -1;
	for(i = lhs->len - 1;i >= 0;i--)
		if(lhs->num[i] != rhs->num[i])
			return lhs->num[i] > rhs->num[i] ? 1 : -1;
	return 0;
}
struct BN BNScanf()
{
	int i;
	char str[MAXN];
	struct BN ans;
	scanf("%s", str);
	ans.len = strlen(str);
	for(i = 0;i < ans.len;i++)
		ans.num[i] = str[ans.len-1-i] - '0';
	return ans;
}
void BNPrint(struct BN a)
{
	if(a.len == 0) putchar('0');
	for(int i = a.len-1;i >= 0;i--)
		putchar(a.num[i] + '0');
	putchar('\n');
}
void BNTrim(struct BN *a)
{
	while(a->len && a->num[a->len - 1] == 0)
		a->len--;
}
void BNAdd(struct BN *a,struct BN *b,struct BN *c)
{
	int i;
	c->len=a->len>b->len?a->len:b->len;
	for(i = a->len;i <= c->len;i++) a->num[i] = 0;
	for(i = b->len;i <= c->len;i++) b->num[i] = 0;
	int carry = 0;
	for(i=0;i<c->len;i++)
	{
		c->num[i]=a->num[i]+b->num[i];
		if(carry){c->num[i]++;carry=0;}
		if(c->num[i]>9){c->num[i]-=10;carry=1;}
	}
	if(carry){c->num[c->len++]=1;c->num[c->len]='\0';}
}
// subtract returns the absolute value
void BNSubtract(struct BN *a,struct BN *b,struct BN *c)
{
	int i;
	if(BNCmp(a, b) < 0){BNSubtract(b, a, c);return;}

	c->len=a->len>b->len?a->len:b->len;
	for(i=a->len;i<c->len;i++) a->num[i]=0;
	for(i=b->len;i<c->len;i++) b->num[i]=0;
	a->num[c->len]=b->num[c->len]='\0';
	int carry = 0;
	for(i = 0;i < c->len;i++){
		c->num[i] = a->num[i] - b->num[i];
		if(carry){c->num[i]--;carry = 0;}
		if(c->num[i] < 0){c->num[i] += 10;carry = 1;}
	}
	BNTrim(c);
}
void BNMultiply(struct BN *a,struct BN *b,struct BN *c){
	int i;
	memset(c->num,0,sizeof(c->num));
	c->len=1;
	for(i=0;i<b->len;i++)
	{
		for(int j=0;j<a->len;j++)
		{
			c->num[i+j]+=(b->num[i]*a->num[j]);
			c->len=i+j+1;
			if(c->num[i+j]>=10){
				c->num[i+j+1]+=(c->num[i+j]/10);
				c->num[i+j]%=10;
				c->len++;
			}
		} 
	} 
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
void BNDiv2(struct BN a,struct BN b,struct BN *c,struct BN *r){
	int i;
	struct BN CONST_10, a_digit, r_temp;
	BNInit(r,0);
	BNInit(&CONST_10, 10);
	for(i = 0;i < a.len/2;i++)
		swap2(a.num+i,a.num+a.len-1-i);
	memset(c->num,0,sizeof(c->num));
	c->len = 0;
    for(i = 0;i < a.len;i++){
    	BNInit(&a_digit, a.num[i]);
    	memcpy(&r_temp, r, sizeof(struct BN));
        BNMultiply(&r_temp, &CONST_10, r);
        memcpy(&r_temp, r, sizeof(struct BN));
        BNAdd(&r_temp, &a_digit, r);
        if(c->len || BNCmp(r, &b) >= 0)
        {
        	while(BNCmp(r, &b) >= 0)
        	{
        		memcpy(&r_temp, r, sizeof(struct BN));
        		BNSubtract(&r_temp, &b, r);
        		c->num[c->len]++;
			}
            c->len++;
        }
    }
    for(i = 0;i < c->len/2;i++)
		swap2(c->num+i,c->num+c->len-1-i);
}
int main()
{
	int T, r;
	scanf("%d", &T);
	while(T--)
	{
		struct BN ans, ans_temp, n, one;
		n = BNScanf();
		BNInit(&one, 1);
		BNInit(&ans, 0);
		while(BNCmp(&n, &one) > 0)
		{
			BNDiv(n, 2, &n, &r);
			memcpy(&ans_temp, &ans, sizeof(struct BN));
			BNAdd(&ans_temp, &n, &ans);
		}
		BNPrint(ans);
	}
	return 0;
}
