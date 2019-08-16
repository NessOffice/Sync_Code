#include <cstdio>
#include <cstring>
#include <algorithm>
struct BigNum{
	char num[20010];
	int len;
}; 
void swap2(char *a,char *b){char t=*a;*a=*b;*b=t;}
void BigNumInitate(struct BigNum *a,int b){
	a->len=0;
	while(b){
		a->num[a->len]=b%10;
		b/=10;
		a->len++;
	}
}
void BigNumPrint(struct BigNum a){
	for(int i=a.len-1;i>=0;i--) printf("%c",a.num[i]+'0');
}
bool BigNumCmp(struct BigNum *a, struct BigNum *b)
{
	if(a->len != b->len) return a->len < b->len;
	for(int i = a->len - 1;i >= 0;i--)
		if(a->num[i] != b->num[i]) return a->num[i] < b->num[i];
	return false;
}
void BigNumMultiply(struct BigNum *a,struct BigNum *b,struct BigNum *c){
	int i;
	memset(c->num,0,sizeof(c->num));c->len=1;
	for(i=0;i<b->len;i++){
		for(int j=0;j<a->len;j++){
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
void BigNumDivide(struct BigNum a,int b,struct BigNum *c){
	for(int i=0;i<a.len/2;i++)
		swap2(a.num+i,a.num+a.len-1-i);
	int r=0;
	c->len=0;
    for(int i=0;i<a.len;i++)
    {
        r=r*10+a.num[i];
        if(c->len||r>=b)
        {
            c->num[c->len]=r/b;
            r=r%b;
            c->len++;
        }
    }
    for(int i=0;i<c->len/2;i++)
		swap2(c->num+i,c->num+c->len-1-i);
}
struct Person{int l, r, w;}persons[1010];
bool PersonCmp(const Person& lhs, const Person& rhs){return lhs.w < rhs.w;}
int main()
{
	int n;
	struct BigNum pi, ans;
	scanf("%d%d%d", &n, &persons[0].l, &persons[0].r);
	BigNumInitate(&pi, persons[0].l);
	BigNumInitate(&ans, 0);
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d", &persons[i].l, &persons[i].r);
		persons[i].w = persons[i].l * persons[i].r;
	}
	std::sort(persons, persons+n, PersonCmp);
	for(int i = 0;i < n;i++)
	{
		struct BigNum temp, temp2, temp3;
		BigNumDivide(pi, persons[i].r, &temp);
		if(BigNumCmp(&ans, &temp))
			memcpy(&ans, &temp, sizeof(temp));
		BigNumInitate(&temp2, persons[i].l);
		BigNumMultiply(&pi, &temp2, &temp3);
		memcpy(&pi, &temp3, sizeof(temp3));
	}
	BigNumPrint(ans);
	return 0;
}
