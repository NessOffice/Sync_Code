#include <stdio.h>
//��λ����ķ��� 
int mask[4],address[4],temp[4]; //mask[i]�洢�ܡ���ס������address[i]����С�Ķ����� 
int min(int a,int b){return a<b?a:b;}
void update(int i){
	if(mask[i]==256) return;
	for(int j=i+1;j<4;j++){//����address�ӵ�һλ��ʼ�в�ͬ�����涼���Բ��� 
		address[j]=0;
		mask[j]=256;
	}
	int temp2,m=1,d=address[i]-temp[i];if(d<0) d=-d;//dΪ���αȽ���temp��address�Ĳ� 
	temp2=temp[i]>address[i]?temp[i]:address[i];//temp2��¼���αȽ��еĽϴ�������������жϱ߽� 
	address[i]=min(address[i],temp[i]);//��һ����16��һ����address��Ϊmask�ı��� 
	while(d){m*=2;d/=2;}
	if(m>mask[i]) mask[i]=m;//����mask 
	address[i]=address[i]/mask[i]*mask[i];
	while(temp2-address[i]==mask[i]){//�жϱ߽磺temp2-address<=mask����С�ڣ��ɸ��ǣ������ڣ�maskҪ���£�addressҲҪ���� 
		mask[i]*=2;
		address[i]=address[i]/mask[i]*mask[i];
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1){
		for(int i=0;i<4;i++){address[i]=-1;mask[i]=1;}//��ʼ����ʹaddress�ܳ�Ϊ��һ����������� 
		while(n--){
			scanf("%d.%d.%d.%d",temp,temp+1,temp+2,temp+3);
			if(address[0]==-1)
				for(int i=0;i<4;i++)
					address[i]=temp[i];
			for(int i=0;i<4;i++)
				if(address[i]!=temp[i]){update(i);break;}//��һ�һ���͸��£����治�ع� 
		}
		printf("%d.%d.%d.%d\n",address[0],address[1],address[2],address[3]);
		printf("%d.%d.%d.%d\n",256-mask[0],256-mask[1],256-mask[2],256-mask[3]);//���256-mask 
	}
	return 0;
} 
