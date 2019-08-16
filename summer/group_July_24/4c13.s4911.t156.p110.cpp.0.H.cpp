#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define MAXN 500005
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
int n,c,b;
bool a[MAXN],lock[MAXN];
int main(){
	n=read<int>();
	c=read<int>();
	b=read<int>();
	for(int i=0;i<b;i++)lock[read<int>()]=1;
	for(int i=n-1;i>1;i--){
		if(lock[i]){
			if(a[i]!=a[i+1])c--;
			continue;
		}
		if(c>1)a[i]=!a[i+1],c--;else a[i]=a[i+1];
	}
	if(c)a[1]=!a[2],c--;else a[1]=a[2];
	for(int i=1;i<=n;i++)putchar(a[i]?'1':'0');
	return 0;
}
