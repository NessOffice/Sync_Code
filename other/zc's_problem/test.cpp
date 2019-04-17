#include <iostream>
#include <cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	char plot[12][12],khar='A';
	memset(plot,'.',sizeof(plot));
	int x=0,y=0,direct[4],p;
	srand((unsigned)time(NULL));
	while(khar<='Z'){
		plot[x][y]=khar++;
		for(int i=0;i<4;i++) direct[i]=1;
		if(!x||plot[x-1][y]!='.') direct[0]=0;
		if(!y||plot[x][y-1]!='.') direct[1]=0;
		if(x==9||plot[x+1][y]!='.') direct[2]=0;
		if(y==9||plot[x][y+1]!='.') direct[3]=0;
		if(!direct[0]&&!direct[1]&&!direct[2]&&!direct[3]) break;
		p=rand()%4;
		while(!direct[p]) p=rand()%4;
		if(p==0) x--;
		if(p==1) y--;
		if(p==2) x++;
		if(p==3) y++;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout<<plot[j][i];
		cout<<endl;
	}
	return 0;
} 
