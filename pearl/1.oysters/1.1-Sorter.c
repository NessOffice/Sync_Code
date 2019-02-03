#include <stdio.h>
#include <string.h>
#define SHIFT 5
#define MAXN 1000
int sorted[MAXN];
void set(int i){sorted[i>>SHIFT] |= (1<<(i & 31));}
int judge(int i){return sorted[i>>SHIFT] && (1<<(i & 31));}
void clr(int i){sorted[i>>SHIFT] &= ~(1<<(i & 31));}
int main()
{
	FILE *fin = fopen("random.txt", "r");
	FILE *fout = fopen("sorted.txt", "w");
	int i;
	for(i = 0;i < MAXN;i++) clc(i);
	
	fprintf(fout, "%d", sorted[0]);
	fclose(fout);
	fclose(fin);
	return 0;
}
