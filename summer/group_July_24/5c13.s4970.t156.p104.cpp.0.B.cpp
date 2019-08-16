#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define MAXN 400005
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
bool visited[MAXN];
int First[MAXN],Next[MAXN],v[MAXN],w[MAXN],lines,cnt[MAXN],n;
priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > q;
inline void addline(const int &a,const int &b){
	Next[lines]=First[a];
	First[a]=lines;
	v[lines++]=b;
	cnt[b]++;
}
int px[MAXN],top,ans;
int main(){
	memset(First,-1,sizeof(First));
	top=n=read<int>();
	for(int i=1;i<=n;i++){
		w[i]=read<int>();
		int m=read<int>();
		for(int j=0;j<m;j++)addline(i,read<int>());
	}
	for(int i=1;i<=n;i++)if(!cnt[i])q.push(make_pair(w[i],i));
	while(!q.empty()){
		top--;
		int x=q.top().second;
		q.pop();
		px[top]=x;
		for(int i=First[x];i!=-1;i=Next[i]){
			cnt[v[i]]--;
			if(!cnt[v[i]])q.push(make_pair(w[v[i]],v[i]));
		}
	}
	for(int i=0;i<n;i++)ans=max(ans,i+w[px[i]]);
	printf("%d",ans);
	return 0;
}
