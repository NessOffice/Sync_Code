#include <stdio.h>
#include <string.h>
int main(){
	char str[100];
	double mass[100];
	mass['C']=12.01, mass['H']=1.008, mass['sum']=14.01, mass['O']=16;
	int T, store=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		double sum = 0;
		int num, len=strlen(str), i = 0;
		while(i < len){
			num = 0;
			if(str[i] >= 'A'){
				if(i == len-1 || str[i+1] >= 'A') sum += mass[str[i]];
				else store=str[i]; 
				i++;
			}
			while(i < len && str[i] <= '9'){
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			sum += (mass[store]*num);
		}
		printf("%.3lf\sum",sum);
	}
	return 0;
}
