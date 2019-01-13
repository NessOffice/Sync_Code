#include <stdio.h>
#include <string.h>
char temp[14],cube1[8],cube2[8]; 
int dir[8][8]={{1,2,3,4,5,6},{6,5,3,4,2,1},{5,1,3,4,6,2},{2,6,3,4,1,5},{4,2,1,6,5,3},{3,2,6,1,5,4}};
int cmp(){
	temp[0]='r';
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++)
			temp[j+1]=cube2[dir[i][j]];
		for(int k=0;k<4;k++){
			char t=temp[2];
			temp[2]=temp[3];
			temp[3]=temp[5];
			temp[5]=temp[4];
			temp[4]=t;
			if(!memcmp(cube1,temp,7*sizeof(char))) return 1;
		}
	}
	return 0;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cube1[0]=cube2[0]='r';
	while(scanf("%s",temp)!=EOF){
		for(int i=0;i<6;i++) cube1[i+1]=temp[i];
		for(int i=6;i<12;i++) cube2[i-5]=temp[i];
		if(cmp()) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}
