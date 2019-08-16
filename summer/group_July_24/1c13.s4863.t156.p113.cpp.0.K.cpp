#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
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
char s1[256],s2[256],a[256],b[256];
int main(){
	int n=read<int>(),m=read<int>();
	gets(s1);
	gets(s2);
	for(int i=0;i<n;i++)a[i]=s1[n-1-i]-'a';
	for(int i=0;i<m;i++)b[i]=s2[m-1-i]-'a';
	for(int i=n;i<m;i++)a[i]=(b[i-n]-a[i-n]+26)%26;
	for(int i=0;i<m;i++)putchar(a[m-i-1]+'a');
	return 0;
}
