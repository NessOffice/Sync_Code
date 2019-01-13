#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=11;
int n,m,t,maxd;
bool g[maxn][maxn],vis[4][maxn*2];
bool guard(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(g[i][j]&&!vis[0][i]&&!vis[1][j]&&!vis[2][i+j]&&!vis[3][i-j+maxn]) return false;
    return true;
}
bool dfs(int i,int j,int d){
    if(d==maxd){
        if(guard())  return true;
        return false;
    }
    while(i<n){
        while(j<m){
            bool tmp1=vis[0][i],tmp2=vis[1][j],tmp3=vis[2][i+j],tmp4=vis[3][i-j+maxn];
            vis[0][i]=vis[1][j]=vis[2][i+j]=vis[3][i-j+maxn]=true;
            if(dfs(i,j+1,d+1)) return true;
            vis[0][i]=tmp1,vis[1][j]=tmp2,vis[2][i+j]=tmp3,vis[3][i-j+maxn]=tmp4;
            ++j;
        }
        j%=m,++i;
    }
    return false;
}
int main()
{
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++){
            getchar();
            for(int j=0;j<m;j++)
                if(getchar()=='X') g[i][j]=true;
        }
        for(maxd=0;maxd<5;++maxd){
            memset(vis,0,sizeof(vis));
            if(dfs(0,0,0)) break;
        }
        printf("Case %d: %d\n",++t,maxd);
    }
    return 0;
}