#include <stdio.h>
#include <string.h>
void swap(int* pa, int* pb)
{
	int *temp = pa;
	pa = pb;
	pb = temp;
}
void strcat(char* str1, char* str2)
{
	while(*++str1);
	while(*str1++ = *str2++);
}
void strcpy(char* str1, char* str2)
{
	while(*str1++ = *str2++);
}
void fuck()
{
	static int motherfucker = 0;
	printf("%d", ++motherfucker);
}
int main()
{
//	int a = 1, b = 2, *pa, *pb;
//	pa = &a, pb = &b;
//	swap(pa, pb);
	// printf("%d %d", *pa, *pb);
	char str1[10] = "11200", str2[10] = "990";
	strcpy(str1, str2);
//	printf("%s", str1);
	// strcat(str1, str2);
	char sb[3][3] = {"ad", "ce", "fb"}, *s = (char *)sb;
	//printf("%c %c", sb[2][1], *(*sb + 4));
//	char naocan[] = "\000";
//	static char nc[] = {"happy"};
//	printf("%d %d", strlen(naocan), sizeof(naocan));
	//char nmb[3] = {'c', 'n', 'm'};
//	printf("%d", sizeof("\x23"));
	//for(int i = 0;i < 10;i++)
	//	fuck();
//	printf("%d", ~1);
//	printf("%d", 2 < 1 ? 3 : 4 < 4 ? 5 : 6);
//	int zz = 1;
	//switch(zz)
	//{
	//	case 0%2:printf("fuck you");break;
		//default:printf("cao you");
	//}
//	int jr[] = {1, 2, 3}, *jj = jr;
//	printf("%d ", *++jj);
//	jj = jr;
//	printf("%d", *(jj++));
//	putchar("0123456789AB"[10]);
//	int i = 0;
//	char a;a = '\0';
//	while(++a) i++;
//	printf("%d", i);
	float a[3][3];
	printf("%d", (int)(a+1)-(int)&a[0][1]);
	return 0;
}
