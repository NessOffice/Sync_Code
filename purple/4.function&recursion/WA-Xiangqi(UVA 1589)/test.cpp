#include <stdio.h>
#include <iostream>
using namespace std;
int n,x,y;
struct piece{
	char type;
	int x,y;
}red[8];
int judge(int i,int way){//1�������Ӳ����� 
	int x0=x,y0=y;
	switch(way){//�ı�generalλ�� 
		case 0:x0--;break;
		case 1:x0++;break;
		case 2:y0--;break;
		case 3:y0++;break;
	}
	int x1=red[i].x,y1=red[i].y;
	if(red[i].type=='G'){
		if(x0!=x1) return 1;//����һ��ֱ���˳� 
		for(int j=0;j<n;j++){//�ж��м������� 
			if(j==i) continue;
			if(red[j].x==x0)
				if((red[j].y-y0)*(red[j].y-y1)<0) return 1;
		}
		return 0;
	}
	if(red[i].type=='R'){//�� 
		if((x0!=x1 && y0!=y1) || (x0==x1 && y0==y1)) return 1;
		if(x0==x1){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].x==x0)
					if((red[j].y-y0)*(red[j].y-y1)<0) return 1;
			}
			return 0;
		}
		if(y0==y1){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].y==y0)
					if((red[j].x-x0)*(red[j].x-x1)<0) return 1;
				}
				return 0;
		}
	}
	if(red[i].type=='C'){//�� 
		if((x0!=x1 && y0!=y1) || (x0==x1 && y0==y1)) return 1;
		int count=0;
		if(x0==x1){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].x==x0)
					if((red[j].y-y0)*(red[j].y-y1)<0) count++;
			}
			if(count==1) return 0;
		}
		if(y0==y1){
		for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].y==y0)
					if((red[j].x-x0)*(red[j].x-x1)<0) count++;
			}
			if(count==1) return 0;
		}
	}
	if(red[i].type=='H'){//�����жϹ������룬���жϰ���� 
		if(x0==x1-2 && (y0==y1-1 || y0==y1+1)){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].x==x1-1 && red[j].y==y1) return 1;
			}
			return 0;
		}
		if(x0==x1+2 && (y0==y1-1 || y0==y1+1)){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].x==x1+1 && red[j].y==y1) return 1;
			}
			return 0;
		}
		if(y0==y1-2 && (x0==x1-1 || x0==x1+1)){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].y==y1-1 && red[j].x==x1) return 1;
			}
			return 0;
		}
		if(y0==y1+2 && (x0==x1-1 || x0==x1+1)){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(red[j].y==y1+1 && red[j].x==x1) return 1;
			}
			return 0;
		}
		return 1;
	}
}
int go(int way){//0���������������� 
	if(way==0 && x==4) return 0;//�߽��ж� 
	if(way==1 && x==6) return 0;
	if(way==2 && y==1) return 0;
	if(way==3 && y==3) return 0;
	for(int i=0;i<n;i++) if(!judge(i,way)) return 0;//�������������Ӿ��������򷵻�0 
	return 1;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>n>>y>>x && n){//ת��x��y������ 
		for(int i=0;i<n;i++)
			cin>>red[i].type>>red[i].y>>red[i].x;
		if(go(0) || go(1) || go(2) || go(3)) cout<<"NO\n";//���ĸ��������һ������������no 
		else cout<<"YES\n";
	}
	return 0;
}
