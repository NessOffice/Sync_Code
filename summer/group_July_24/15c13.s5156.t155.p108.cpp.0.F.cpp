#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int g[2505][2505];
int n;ll ans;
int used[2505],pass[2505],eg[2505],more,queue[2505];
void combine(int id,ll &sum)
{
	int tot=0,from,i,j,k;
	for(;id!=0&&!pass[id];id=eg[id])
	{
		queue[tot++]=id;
		pass[id]=1;
	}
	for(from=0;from<tot&&queue[from]!=id;++from);
	if(from==tot) return;
	more=1;
	for(i=from;i<tot;i++)
	{
		sum+=g[eg[queue[i]]][queue[i]];
		if(i!=from)
		{
			used[queue[i]]=1;
			for(j=1;j<=n;j++) if(!used[j])
			{
				if(g[queue[i]][j]<g[id][j])
				{
					g[id][j]=g[queue[i]][j];
				}
			}
		}
	}
	for(i=1;i<=n;i++) if(!used[i]&&i!=id)
	{
		for(j=from;j<tot;j++)
		{
			k=queue[j];
			if(g[i][id]>g[i][k]-g[eg[k]][k])
			{
				g[i][id]=g[i][k]-g[eg[k]][k];
			}
		}
	}
}
ll mdst(int root)
{
	int i,j,k;
	ll sum=0;
	memset(used,0,sizeof(used));
	int T=50;
	while(T--)
	{
		more=0;
		memset(eg,0,sizeof(eg));
		for(i=1;i<=n;i++) if(!used[i]&&i!=root)
		{
			for(j=1,k=0;j<=n;j++) if(!used[j]&&i!=j)
			{
				if(k==0||g[j][i]<g[k][i]) k=j;
			}
			eg[i]=k;
		}
		memset(pass,0,sizeof(pass));
		for(i=1;i<=n;i++) if(!used[i]&&!pass[i]&&i!=root) combine(i,sum);
	}
	for(i=1;i<=n;i++) if(!used[i]&&i!=root) sum+=g[eg[i]][i];
	return sum;
}
int main()
{
	cin>>n;n++;
	memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=2;i<=n;i++)
	{
		int fa,x,y;cin>>fa>>x;
		fa++;
		g[fa][i]=0;
		ans+=x;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&y);
			if(j==fa) continue;
			g[j][i]=y-x;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<g[i][j]<<" ";
		cout<<endl;
	}//*/
	
	cout<<ans+mdst(1);
	return 0;
}
