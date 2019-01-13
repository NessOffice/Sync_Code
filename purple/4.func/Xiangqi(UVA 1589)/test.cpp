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
int judge(int i,int way){//返回1表明该子不对将军构成威胁 
	x0=x,y0=y;
	switch(way){//改变general位置 
		case 0:x0--;break;
		case 1:x0++;break;
		case 2:y0--;break;
		case 3:y0++;break;
		default:break;	
	}
	x1=red[i].x,y1=red[i].y;
	if(red[i].type=='G'){
		if(x0!=x1) return 1;//两将若不在一列，直接退出 
		if(PieceCount('x',i)==0) return 0;
		else return 1;
	}
	if(red[i].type=='R'){//车 
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
	if(red[i].type=='C'){//炮 
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
	if(red[i].type=='H'){//马，先判断攻击距离，再判断绊马脚 
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
int go(int way){//0表明被将军或不能走 
	if(way==0 && x==4) return 0;//边界判断 
	if(way==1 && x==6) return 0;
	if(way==2 && y==1) return 0;
	if(way==3 && y==3) return 0;
	if(way==-1){for(int i=0;i<n;i++) if(red[i].type=='G') if(!judge(i,way)) return 1;return 0;}
	else for(int i=0;i<n;i++) if(!judge(i,way)) return 0;//若所有其他旗子均不将军则返回0 
	return 1;
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n>>y>>x && n){//转换x，y再输入 
		for(int i=0;i<n;i++)
			cin>>red[i].type>>red[i].y>>red[i].x;
		if(go(-1) || go(0) || go(1) || go(2) || go(3)) cout<<"NO\n";//若四个方向存在一个不被将军则no 
		else cout<<"YES\n";
	}
	return 0;
}
