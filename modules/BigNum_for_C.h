#include <stdio.h>
#include <string.h>
struct BigNum{
	char num[100];
	int len;
}; 
void swap(char *a,char *b){char t=*a;*a=*b;*b=t;}
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
void BigNumAdd(struct BigNum *a,struct BigNum *b,struct BigNum *c){
	int i;
	c->len=a->len>b->len?a->len:b->len;
	for(i=a->len;i<c->len;i++) a->num[i]=0;
	for(i=b->len;i<c->len;i++) b->num[i]=0;
	a->num[c->len]=b->num[c->len]='\0';
	int carry=0;
	for(i=0;i<c->len;i++){
		c->num[i]=a->num[i]+b->num[i];
		if(carry){c->num[i]++;carry=0;}
		if(c->num[i]>9){c->num[i]-=10;carry=1;}
	}
	if(carry){c->num[c->len++]=1;c->num[c->len]='\0';}
}
void BigNumSubtract(struct BigNum *a,struct BigNum *b,struct BigNum *c){
	int i;
	c->len=a->len>b->len?a->len:b->len;
	for(i=a->len;i<c->len;i++) a->num[i]=0;
	for(i=b->len;i<c->len;i++) b->num[i]=0;
	a->num[c->len]=b->num[c->len]='\0';
	int carry=0;
	for(i=0;i<c->len;i++){
		c->num[i]=a->num[i]+b->num[i];
		if(carry){c->num[i]++;carry=0;}
		if(c->num[i]>9){c->num[i]-=10;carry=1;}
	}
	if(carry){c->num[c->len++]=1;c->num[c->len]='\0';}
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
		swap(a.num+i,a.num+a.len-1-i);
	int remainder=0;
	c->len=0;
    for(int i=0;i<a.len;i++)
    {
        remainder=remainder*10+a.num[i];
        if(c->len||remainder>=b)
        {
            c->num[c->len]=remainder/b;
            remainder=remainder%b;
            c->len++;
        }
    }
    for(int i=0;i<c->len/2;i++)
		swap(c->num+i,c->num+c->len-1-i);
}
void BigNumDivide2(struct BigNum a,struct BigNum b,struct BigNum *c,struct BigNum *d){
	int i;
	struct BigNum CONST_10,a_now;
	BigNumInitate(d,0);
	BigNumInitate(&CONST_10,10);
	for(i=0;i<a.len/2;i++)
		swap(a.num+i,a.num+a.len-1-i);
	memset(c->num,0,sizeof(c->num));
	c->len=0;
    for(i=0;i<a.len;i++){
    	BigNumInitate(&a_now,a.num[i]);
        BigNumMultiply(*d,CONST_10,d);
        BigNumAdd(*d,a_now,d);
        if(c->len||BigNumCmp(*d,b)>=0){
        	while(BigNumCmp(*d,b)>=0){
        		BigNumSubtract(*d,b,d);
        		c->num[c->len]++;
			}
            c->len++;
        }
    }
    if(!c->len) c->len=1;
    for(i=0;i<c->len/2;i++)
		swap(c->num+i,c->num+c->len-1-i);
}
/*int main(){
	int i;
	struct BigNum a,b,c;
	int d=100;
	for(i=0;i<a.len;i++) a.num[i]-='0';
	for(i=0;i<b.len;i++) b.num[i]-='0';
	for(i=0;i<a.len/2;i++)
		swap(a.num+i,a.num+a.len-1-i);
	for(i=0;i<b.len/2;i++)
		swap(b.num+i,b.num+b.len-1-i);
	BigNumInitate(&a,4950);
	BigNumDivide(a,d,&c);
	BigNumPrint(c);
	return 0;
} 
