#include <stdio.h>
int count[8];
void count_13(int year,int *week){
	int k,leap;
	int tab[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31},
	};
	leap=(year%4==0&&year%100!=0)||year%400==0;
	*week=(*week+13-1-1)%7+1;
	count[*week]++;
	for(k=1;k<12;k++){
		*week=(*week+tab[leap][k]-1)%7+1;
		count[*week]++;
	}
	*week=(*week+31+1-13-1)%7+1;
}
int main(){
	int year,n,week=1;
	scanf("%d",&n);
	for(int i=1;i<=7;i++) count[i]=0;
	for(year=1900;year<1900+n;year++)
		count_13(year,&week); 
	for(int i=1;i<=7;i++) printf("%d ",count[i]);
	return 0;
} 
