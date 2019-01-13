#include <stdio.h>
#include <iostream>
using namespace std;
int n,x,y,x0,y0,x1,y1;
struct piece{
	char type;
	int x,y;
}red[8];
int PieceCount(char type,int i){
	int count=0;
	for(int j=0;j<n;j++){
			if(j==i) continue;
			if(type=='x'){
				if(red[j].x==x0)
					if((red[j].y-y0)*(red[j].y-y1)<0) count++;
			}
			if(type=='y')
				if(red[j].y==y0)
					if((red[j].x-x0)*(red[j].x-x1)<0) count++;
		}
	return count;
} 
int judge(int i,int way){//����1�������Ӳ��Խ���������в 
	x0=x,y0=y;
	switch(way){//�ı�generalλ�� 
		case 0:x0--;break;
		case 1:x0++;break;
		case 2:y0--;break;
		case 3:y0++;break;
		default:break;	
	}
	x1=red[i].x,y1=red[i].y;
	if(red[i].type=='G'){
		if(x0!=x1) return 1;//����������һ�У�ֱ���˳� 
		if(PieceCount('x',i)==0) return 0;
		else return 1;
	}
	if(red[i].type=='R'){//�� 
		if((x0!=x1 && y0!=y1) || (x0==x1 && y0==y1)) return 1;
		if(x0==x1){
			if(PieceCount('x',i)==0) return 0;
			else return 1;
		}
		if(y0==y1){
			if(PieceCount('y',i)==0) return 0;
			else return 1;
		}
	}
	if(red[i].type=='C'){//�� 
		if((x0!=x1 && y0!=y1) || (x0==x1 && y0==y1)) return 1;
		if(x0==x1){
			if(PieceCount('x',i)==1) return 0;
			else return 1;
		}
		if(y0==y1){
			if(PieceCount('y',i)==1) return 0;
			else return 1;
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
	if(way==-1){for(int i=0;i<n;i++) if(red[i].type=='G') if(!judge(i,way)) return 1;return 0;}
	else for(int i=0;i<n;i++) if(!judge(i,way)) return 0;//�������������Ӿ��������򷵻�0 
	return 1;
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n>>y>>x && n){//ת��x��y������ 
		for(int i=0;i<n;i++)
			cin>>red[i].type>>red[i].y>>red[i].x;
		if(go(-1) || go(0) || go(1) || go(2) || go(3)) cout<<"NO\n";//���ĸ��������һ������������no 
		else cout<<"YES\n";
	}
	return 0;
}
