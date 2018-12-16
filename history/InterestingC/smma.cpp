#include <stdio.h>
int main()
{
	const char* star[] = {"Aries","Taurus","Gemini","Cancer","Leo",
	"Virgo","Libra","Scorpio","Sagittarius","Capricorn","Aquarius",
	"Pisces"};
	int T, month, day,flag;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &month, &day);
		switch(month)
		{
			case 1:
				if(day<20) flag = 9;
				else flag = 10;
				break;
			case 2:
				if(day<19) flag = 10;
				else flag = 11;
				break;
			case 3:
				if(day<21) flag = 11;
				else flag = 0;
				break;
			case 4:
				if(day<20) flag = 0;
				else flag = 1;
				break;
			case 5:
				if(day<21) flag = 1;
				else flag = 2;
				break;
			case 6:
				if(day<22) flag = 2;
				else flag = 3;
				break;
			case 7:
				if(day<23) flag = 3;
				else flag = 4;
				break;
			case 8:
				if(day<23) flag = 4;
				else flag = 5;
				break;
			case 9:
				if(day<23) flag = 5;
				else flag = 6;
				break;
			case 10:
				if(day<24) flag = 6;
				else flag = 7;
				break;
			case 11:
				if(day<23) flag = 7;
				else flag = 8;
				break;
			case 12:
				if(day<22) flag = 8;
				else flag = 9;
				break;
		}
		printf("%s\n", star[flag]);
	}
	return 0;
}
