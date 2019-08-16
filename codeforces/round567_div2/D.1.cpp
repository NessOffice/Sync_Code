#include<bits/stdc++.h>
using namespace std;
const int N=500;
long long a[N],t;
int n,m,q,i,cnt[N],x;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++) scanf("%d",&x),a[i]=1ll*(cnt[x]++)*m+x;
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) a[i]-=i;
	for (;q--;){
		scanf("%lld",&t),t-=n;
		if (t>a[n]) t+=n;
		else t+=lower_bound(a+1,a+n+1,t)-a-1;
		printf("%lld\n",(t-1)%m+1);
	}
}