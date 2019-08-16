#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXS 1000006
using namespace std;
template <typename T> inline T read(){
	T x=0,f=1;char ch=getchar();int t=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(ch=='.'){
		ch=getchar();
		while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();t++;}
		while(t--)x/=10.0;
	}
	return x*f;
}
char e1[MAXS],e2[MAXS];
int n1,n2,r1[MAXS],r2[MAXS],stk[MAXS],l1,l2,s1,s2,a[MAXS],b[MAXS],ma[MAXS],mb[MAXS];
int phrase1(int l,int r,int mark){
	int p=l,t=0;
	bool eq=1;
	while(p<=r){
		while(p<=r&&(e1[p]<'0'||e1[p]>'9'))p++;
		if(p<=r&&e1[p]>='0'&&e1[p]<='9'){t++,l1++;ma[l1-1]=mark;}
		while(p<=r&&e1[p]>='0'&&e1[p]<='9'){a[l1-1]=a[l1-1]*10+e1[p]-'0';p++;}
	}
	for(int i=l1-t;i<l1;i++)if(a[i]!=a[l1-1]){eq=0;break;}
	if(mark&&eq){
		for(int i=l1-t;i<l1;i++)ma[i]=0;
		s1--;
	}
	return t;
}
int phrase2(int l,int r,int mark){
	int p=l,t=0;
	bool eq=1;
	while(p<=r){
		while(p<=r&&(e2[p]<'0'||e2[p]>'9'))p++;
		if(p<=r&&e2[p]>='0'&&e2[p]<='9'){t++,l2++;mb[l2-1]=mark;}
		while(p<=r&&e2[p]>='0'&&e2[p]<='9'){b[l2-1]=b[l2-1]*10+e2[p]-'0';p++;}
	}
	for(int i=l2-t;i<l2;i++)if(a[i]!=a[l2-1]){eq=0;break;}
	if(mark&&eq){
		for(int i=l2-t;i<l2;i++)mb[i]=0;
		s2--;
	}
	return t;
}
int main(){
	int top=0,p;
	fgets(e1,MAXS,stdin);
	fgets(e2,MAXS,stdin);
	n1=strlen(e1)-1;
	n2=strlen(e2)-1;
	for(int i=0;i<n1;i++){
		if(e1[i]=='(')stk[top++]=i;
		if(e1[i]==')')r1[stk[--top]]=i;
	}
	top=0;
	for(int i=0;i<n2;i++){
		if(e2[i]=='(')stk[top++]=i;
		if(e2[i]==')')r2[stk[--top]]=i;
	}
	p=0;
	while(p<n1){
		if(e1[p]=='s'&&e1[p+1]=='o'){
			int t=phrase1(p+6,r1[p+6],0);
			sort(a+l1-t,a+l1);
			p=r1[p+6];
		}else if(e1[p]=='s'&&e1[p+1]=='h'){
			int t=phrase1(p+7,r1[p+7],++s1);
			sort(a+l1-t,a+l1);
			p=r1[p+7];
		}else{
			if(e1[p]<'0'||e1[p]>'9'){p++;continue;}
			int x=0;
			while(p<n1&&e1[p]>='0'&&e1[p]<='9'){x=x*10+e1[p]-'0';p++;}
			a[l1++]=x;
		}
	}
	p=0;
	while(p<n2){
		if(e2[p]=='s'&&e2[p+1]=='o'){
			int t=phrase2(p+6,r2[p+6],0);
			sort(b+l2-t,b+l2);
			p=r2[p+6];
		}else if(e2[p]=='s'&&e2[p+1]=='h'){
			int t=phrase2(p+7,r2[p+7],++s2);
			sort(b+l2-t,b+l2);
			p=r2[p+7];
		}else{
			if(e2[p]<'0'||e2[p]>'9'){p++;continue;}
			int x=0;
			while(p<n2&&e2[p]>='0'&&e2[p]<='9'){x=x*10+e2[p]-'0';p++;}
			b[l2++]=x;
		}
	}
	if(l1!=l2){
		puts("not equal");
		return 0;
	}
	for(int i=0;i<l1;i++)if(a[i]!=b[i]||ma[i]!=mb[i]){
		puts("not equal");
		return 0;
	}
	puts("equal");
	return 0;
}
