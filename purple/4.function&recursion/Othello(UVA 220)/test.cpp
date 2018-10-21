#include <stdio.h>
int board[9][9],player,b,w,count;
int search(int type,int y,int x){
	if(board[y][x] && type=='L') return 0;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			if(!i&&!j) continue;
			int y0=y+i,x0=x+j,flag=0;
			while(y0>=0&&y0<8&&x0>=0&&x0<8&&board[y0][x0]==-player){
				y0+=i;
				x0+=j;
				flag++;
			}
			if(y0>=0&&y0<8&&x0>=0&&x0<8&&board[y0][x0]==player&&flag){
				if(type=='M'){
					int y1=y+i,x1=x+j;
					while(y1>=0&&y1<8&&x1>=0&&x1<8&&board[y1][x1]==-player){
						board[y1][x1]*=(-1);
						if(player==1){w++;b--;}
						else{b++;w--;}
						y1+=i;
						x1+=j;
					}
				}
				if(type=='L'){
					if(count++) putchar(' ');
					printf("(%d,%d)",y+1,x+1);
					return 1;
				}
				if(type=='N') return 1;
			}
		}
	return 0;
}
void print(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			switch(board[i][j]){
				case 0:putchar('-');break;
				case 1:putchar('W');break;
				case -1:putchar('B');break;
			}
		}
		putchar('\n');
	}
}
char scan(){
	char c;
	c=getchar();
	while(c=='\r'||c=='\n') c=getchar();
	return c;
}
int main(){
	int n,kase=0,x,y,num;
	char c,cmd; 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--){
		b=w=0;
		if(kase++) putchar('\n');
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				board[i][j]=0;
				c=scan();
				if(c=='W'){board[i][j]=1;w++;}
				if(c=='B'){board[i][j]=-1;b++;}
			}
		}
		c=scan();
		if(c=='W') player=1;
		else player=-1;
		while(cmd=scan()){
			count=0;
			if(cmd=='Q') break;
			if(cmd=='L'){
				int flag=1;
				for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(search(cmd,i,j)) flag=0;
				if(flag) printf("No legal move.");
				putchar('\n');
			}
			if(cmd=='M'){
				scanf("%d",&num);
				x=num%10-1;y=num/10-1;
				if(!search('N',y,x)) player*=(-1);
				board[y][x]=player;
				if(player==1) w++;
				else b++;
				search(cmd,y,x);
				printf("Black - %2d White - %2d\n",b,w);
				player*=(-1);
			}
		}
		print();
	}
	return 0;
}
