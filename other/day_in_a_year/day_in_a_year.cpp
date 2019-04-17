#include <stdio.h>
void month_day(int year,int *yearday,int pmonth,int pday); 
int main(){
	int year,yearday,month,day;
	scanf("%d/%d/%d",&year,&month,&day);
	month_day(year,&yearday,month,day);
	printf("%d",yearday);
	return 0;
} 
void month_day(int year,int *yearday,int pmonth,int pday){
	int k,leap;
	*yearday = 0;
	int tab[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31},
	};
	leap=(year%4==0&&year%100!=0)||year%400==0;
	for(k=1;k<=pmonth;k++){
		if(k == pmonth) *yearday += pday;
		else *yearday+=tab[leap][k];
	}
}

