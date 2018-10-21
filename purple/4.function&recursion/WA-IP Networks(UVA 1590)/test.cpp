#include <stdio.h>
//非位计算的方法 
int mask[4],address[4],temp[4]; //mask[i]存储能“遮住”所有address[i]的最小的二的幂 
int min(int a,int b){return a<b?a:b;}
void update(int i){
	if(mask[i]==256) return;
	for(int j=i+1;j<4;j++){//假如address从第一位开始有不同，后面都可以不管 
		address[j]=0;
		mask[j]=256;
	}
	int temp2,m=1,d=address[i]-temp[i];if(d<0) d=-d;//d为本次比较中temp与address的差 
	temp2=temp[i]>address[i]?temp[i]:address[i];//temp2记录本次比较中的较大数，方便后面判断边界 
	address[i]=min(address[i],temp[i]);//这一行与16行一起让address变为mask的倍数 
	while(d){m*=2;d/=2;}
	if(m>mask[i]) mask[i]=m;//更新mask 
	address[i]=address[i]/mask[i]*mask[i];
	while(temp2-address[i]==mask[i]){//判断边界：temp2-address<=mask，若小于，可覆盖；若等于，mask要更新，address也要更新 
		mask[i]*=2;
		address[i]=address[i]/mask[i]*mask[i];
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<4;i++){address[i]=-1;mask[i]=1;}//初始化，使address能成为第一次输入的序列 
		while(n--){
			scanf("%d.%d.%d.%d",temp,temp+1,temp+2,temp+3);
			if(address[0]==-1)
				for(int i=0;i<4;i++)
					address[i]=temp[i];
			for(int i=0;i<4;i++)
				if(address[i]!=temp[i]){update(i);break;}//哪一项不一样就更新，后面不必管 
		}
		printf("%d.%d.%d.%d\n",address[0],address[1],address[2],address[3]);
		printf("%d.%d.%d.%d\n",256-mask[0],256-mask[1],256-mask[2],256-mask[3]);//输出256-mask 
	}
	return 0;
} 
