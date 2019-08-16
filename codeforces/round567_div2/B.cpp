#include <stdio.h>
#include <string.h>
const int maxl = 1e5 + 5; // caution
struct BN
{
	char num[maxl];// the digits are stored reversely
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
	char str[maxl];
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
int main(){
    int L;
    scanf("%d", &L);
    struct BN origin, ans, lhs, rhs, ans1, ans2;
    origin = BNScanf();
    int mid = L/2;
    for(int i = 0;;i++)
    {
        int len1, len2, flag = 0;
        if(L & 1){
            len1 = mid-i;
            len2 = mid+i+1;
        }else{
            len1 = mid-i;
            len2 = mid+i;
        }
        lhs.len = len1;
        rhs.len = L - len1;
        for(int j = 0;j < len1;j++)
            lhs.num[j] = origin.num[j];
        for(int j = len1;j < L;j++)
            rhs.num[j-len1] = origin.num[j];
        if(lhs.num[len1-1] != 0)
        {
            flag = 1;
            BNAdd(lhs, rhs, &ans1);
            memcpy(&ans, &ans1, sizeof(struct BN));
        }

        if(len2 > L) continue;
        lhs.len = len2;
        rhs.len = L - len2;
        for(int j = 0;j < len2;j++)
            lhs.num[j] = origin.num[j];
        for(int j = len2;j < L;j++)
            rhs.num[j-len2] = origin.num[j];
        if(lhs.num[len2-1] != 0)
        {
            BNAdd(lhs, rhs, &ans2);
            if(flag){
                if(BNCmp(&ans1, &ans2) > 0)
                    memcpy(&ans, &ans2, sizeof(struct BN));
            }else{
                memcpy(&ans, &ans2, sizeof(struct BN));
                flag = 1;
            }
        }
        if(flag) break;
    }
    BNPrint(ans);
	return 0;
}
