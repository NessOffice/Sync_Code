#include <stdio.h>
#include <string.h>
int main(){
	char s[20],buf[99];
	int abc,de,x,y,z;
	scanf("%s",s);
	int count=0;
	for(abc=100;abc<1000;abc++)
		for(de=10;de<100;de++){
			x=de%10*abc;
			y=de/10*abc;
			z=abc*de;
			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
			int ok=1,len=strlen(buf);
			for(int i=0;i<len;i++)
				if(strchr(s,buf[i])==NULL) ok=0;
			if(ok){
				printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%5d\n-----\n%5d\n\n",++count,abc,de,x,y,z);
			}
		}
	return 0;
} 
