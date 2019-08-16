#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define ll long long
#define MAXN 1005
#define EPS 1e-4
#define PI 3.141592653589793238462643383279502884197169399
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
int First[MAXN],Next[MAXN*2],v[MAXN*2],lines;
inline void addline(const int &a,const int &b){
	Next[lines]=First[a];
	First[a]=lines;
	v[lines++]=b;
}
bool visited[MAXN];
int n,cnt[MAXN],Fa[MAXN];
int dfs(int x){
	visited[x]=1;
	for(int i=First[x];i!=-1;i=Next[i]){
		if(visited[v[i]])continue;
		Fa[v[i]]=x;
		cnt[x]+=dfs(v[i])+1;
	}
	return cnt[x];
}
double ans[MAXN][2];
void work(int root,double th0,double wt0){
	//printf("!!!-->%d %.10lf %.10lf\n",root,th0,wt0);
	double x0=ans[root][0],y0=ans[root][1];
	wt0-=2*EPS;
	double st=th0-wt0/2;
	double cnti=0,cntr=cnt[root];
	for(int i=First[root];i!=-1;i=Next[i]){
		if(Fa[v[i]]!=root)continue;
		cnti=cnt[v[i]];
		double wti=wt0*(cnti+1)/cntr;
		double thi=st+wti/2;
		ans[v[i]][0]=x0+cos(thi);
		ans[v[i]][1]=y0+sin(thi);
		work(v[i],thi,min(PI,wti*2));
		st+=wti;
	}
}
int main(){
	memset(First,-1,sizeof(First));
	n=read<int>();
	for(int i=1;i<n;i++){
		int x=read<int>(),y=read<int>();
		addline(x,y);
		addline(y,x);
	}
	dfs(1);
	work(1,0,2*PI);
	for(int i=1;i<=n;i++)printf("%.10lf %.10lf\n",ans[i][0],ans[i][1]);
	return 0;
}
