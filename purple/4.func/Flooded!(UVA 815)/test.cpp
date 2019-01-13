#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int region=1,i,n,m,height[909],sum;
	double x,volumn;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m) && n)
	{
		sum=0;
		for(i=0;i<n*m;i++) scanf("%d",height+i);
		scanf("%lf",&volumn);
		sort(height,height+n*m);
		volumn/=100.0;
		for(i=0;i<n*m;)
		{
			if(i==n*m-1 || sum+(i+1)*(height[i+1]-height[i])>=volumn) break;
			i++;
			sum+=(i*(height[i]-height[i-1]));
		}
		i++;
		x=(volumn-sum)*1.0/i;
		printf("Region %d\n",region++);
		printf("Water level is %.2lf meters.\n",x+height[i-1]);
		printf("%.2lf percent of the region is under water.\n\n",i*100.0/(n*m));
	}
	return 0;
}
