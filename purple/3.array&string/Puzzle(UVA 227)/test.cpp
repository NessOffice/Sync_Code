#include <stdio.h>
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase=0,bx,by,x,y;
	char s[7][7],cmd[100];
	while(gets(s[0])){
		int count=0,flag=0;
		if(s[0][0]=='Z') break;
		for(int i=1;i<5;i++)
			gets(s[i]);
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(s[i][j]==' ')
					bx=i,by=j;
		while(scanf("%c",&cmd[++count]) &&cmd[count]!='0');
		getchar();
		x=bx,y=by;
		for(int i=1;i<count;i++){
			switch(cmd[i]){
				case 'A':x-=1;break;
				case 'B':x+=1;break;
				case 'L':y-=1;break;
				case 'R':y+=1;
			}
			if(x<0||x>4||y<0||y>4){
				flag=1;
				break;
			}
			s[bx][by]=s[x][y];
			s[bx=x][by=y]=' ';
		}
		if(kase++) printf("\n");
		printf("Puzzle #%d:\n",kase);
		if(flag) printf("This puzzle has no final configuration.\n");
		else{
			for(int i=0;i<5;i++){
				for(int j=0;j<4;j++)
					printf("%c ",s[i][j]);
				printf("%c\n",s[i][4]);
			}
		}
	}
	return 0;
}

