#include <stdio.h>
#define MAXN 10000
int n,r,c;
struct command{
	char type[5];
	int r1,c1,r2,c2;
	int num,x[20];
}cmd[MAXN];
int map(int *r,int *c){
	for(int i=0;i<n;i++){
		if(cmd[i].type[0]=='E'){
			if(cmd[i].r1==*r &&cmd[i].c1==*c){*r=cmd[i].r2;*c=cmd[i].c2;}
			else if(cmd[i].r2==*r &&cmd[i].c2==*c){*r=cmd[i].r1;*c=cmd[i].c1;}
		}
		else{
			int dr=0,dc=0;
			for(int j=0;j<cmd[i].num;j++){
				int x=cmd[i].x[j];
				if(cmd[i].type[0]=='I'){
					if(x<=*r && cmd[i].type[1]=='R') dr++;
					if(x<=*c && cmd[i].type[1]=='C') dc++;
				}
				else{
					if(x==*r && cmd[i].type[1]=='R') return 0;
					if(x==*c && cmd[i].type[1]=='C') return 0;
					if(x<*r && cmd[i].type[1]=='R') dr--;
					if(x<*c && cmd[i].type[1]=='C') dc--;
				}
			}
			*r+=dr;*c+=dc;
		}
	}
	return 1;
}
int main(){
	int rq,cq,kase=0,q; 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&r,&c)&&r){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",cmd[i].type);
			if(cmd[i].type[0]=='E')
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else{
				scanf("%d",&cmd[i].num);
				for(int j=0;j<cmd[i].num;j++)
					scanf("%d",&cmd[i].x[j]);
			}
		}
		if(kase++) putchar('\n');
		printf("Spreadsheet #%d\n",kase);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&rq,&cq);
			printf("Cell data in (%d,%d) ",rq,cq);
			if(!map(&rq,&cq)) printf("GONE\n");
			else printf("moved to (%d,%d)\n",rq,cq);
		}
	}
	return 0;
}
