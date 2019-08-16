#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define MAXN 300005
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
int a[MAXN],n;
ll p;
bool cmp(const ll &a,const ll &b){
	return a>b;
}
int main(){
	n=read<int>();
	p=read<ll>();
	n--;
	for(int i=0;i<n;i++)a[i]=read<ll>();
	sort(a,a+n,cmp);
	int k=1;
	while(p>=a[k-1]){
		while(k<n&&a[k]==a[k-1])k++;
		if(k<n&&p-(a[k-1]-a[k])*k>=a[k]){
			p-=(a[k-1]-a[k])*k;
			ans+=(a[k-1]-a[k])*k;
			a[k-1]=a[k];
		}else{
			
			ll t=(p-a[k-1]]);
			ans+=t/(k-1)*k;
			p-=t/(k-1)*k;
			a[k-1]-=t;
			ans+=p-a[k-1]+1;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
